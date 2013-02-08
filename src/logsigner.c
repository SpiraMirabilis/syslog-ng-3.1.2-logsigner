/*
 * Copyright (c) Sep. 2012 Christos Tsopokis, Department of Informatics, 
 * University of Piraeus, Athens, Greece
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * Note that this permission is granted for only version 2 of the GPL.
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * It is not originally adopted by Balabit as official part of 
 * syslog-ng-3.1.2 version but it is implemented with the hope to be a
 * basis for introducing logsigning mechanisms in syslog-ng OSE.
 *
 * The perpose of this library is to add a patch at the syslog-ng-3.1.2
 * version, supplying secure logging techniques for message signing by
 * the use of Message Authentication Codes. Apart from OpenSSL library
 * we used some external libraries imlementing md5, sha1, hmac-md5 and
 * hmac-sha1 mechanisms.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <unistd.h>
#include <fcntl.h>
#include <evtlog.h>
#include <errno.h>
#include <openssl/aes.h>
#include <sys/stat.h>

#include "logsigner.h"
#include "logtransport.h"
#include "sha1.h"
#include "md5.h"
#include "hmac-md5.h"
#include "hmac-sha1.h"
#include "memxor.h"
#include "messages.h"

void compute_md5(const GString *data, char *md5str)
{
  char md5res[MD5_BIN_SIZE];
  struct md5_ctx tmp_hash;
  int i;

  md5_init_ctx(&tmp_hash);
  md5_process_bytes((char *)data->str, (size_t)data->len, &tmp_hash);
  md5_finish_ctx(&tmp_hash, md5res);

  for(i = 0; i < sizeof(md5res); i++)
    sprintf(md5str + i*2, "%.2hhx", md5res[i]);
}

void compute_sha1(const GString *data, char *sha1str)
{
  char sha1res[SHA1_BIN_SIZE];
  struct sha1_ctx tmp_hash;
  int i;

  sha1_init_ctx(&tmp_hash);
  sha1_process_bytes((char *)data->str, (size_t)data->len, &tmp_hash);
  sha1_finish_ctx(&tmp_hash, sha1res);

  for(i = 0; i < sizeof(sha1res); i++)
    sprintf(sha1str + i*2, "%.2hhx", sha1res[i]);
}

void compute_mac(GString *msg, GString *key, char *macstr, int flag)
{
  char *macres;
  int i, size;

  size = (flag == LS_HFO_SHA1) ? SHA1_BIN_SIZE : MD5_BIN_SIZE;
  macres = (char *) malloc(size + 1);

  if (flag == LS_HFO_SHA1)
    hmac_sha1(msg->str, msg->len, key->str, key->len, macres);
  else
    hmac_md5(msg->str, msg->len, key->str, key->len, macres);

  for (i = 0; i < size; i++)
    sprintf(macstr + i*2, "%.2hhx", macres[i]);
  free(macres);
}

int blocks(gsize len)
{
  int nblocks = len / AES_BLOCK_SIZE;
  if (len % AES_BLOCK_SIZE > 0)
    return ++nblocks;
  else
    return nblocks;
}

gboolean log_signer_seed_buffering(GString *seedbuf, gchar *filename)
{
  FILE *in;
  int c;

  if (!(in = fopen((char *) filename, "r")))
    return FALSE;

  fseek(in, 0, SEEK_SET);
  while((c = fgetc(in)) != EOF)
    g_string_append_c(seedbuf, (gchar) c);
  fclose(in);
  return TRUE;
}

void log_signer_kdf(GString *plain_passwd, GString *passwd)
{
  unsigned char digest[40];

  compute_sha1(plain_passwd, (char *)digest);
  g_string_erase(plain_passwd, 0, -1);
  g_string_assign(passwd, (gchar *) digest);
  memset(digest, '\0', sizeof(digest));
}

GString *log_signer_AES_ecb_encrypt(GString *initial, const GString *key, const int mode)
{
  GString *result = NULL;
  AES_KEY aes_ks1;
  int i;

  result = g_string_sized_new(512);

  memset(&aes_ks1, '\0', sizeof(AES_KEY));

  if (mode == AES_ENCRYPT)
    AES_set_encrypt_key((unsigned char *) key->str, 128, &aes_ks1);
  else if (mode == AES_DECRYPT)
    AES_set_decrypt_key((unsigned char *) key->str, 128, &aes_ks1);
  else
    return NULL;

  for (i = 0; i < blocks(initial->len); i++)
    AES_ecb_encrypt((unsigned char *) initial->str + (i * AES_BLOCK_SIZE), 
        (unsigned char *) result->str + (i * AES_BLOCK_SIZE), &aes_ks1, mode);
  result->len = i * AES_BLOCK_SIZE;

  return result;
}

GString *log_signer_passwd_retriever()
{
  GString *plain_passwd = NULL;
  GString *passwd = NULL;

  plain_passwd = g_string_sized_new(512);
  passwd = g_string_sized_new(64);

  plain_passwd->str = (gchar *) getpass("Decryption key: ");
  plain_passwd->len = strlen((char *) plain_passwd->str);
  log_signer_kdf(plain_passwd, passwd);

  return passwd;
}

gchar *log_signer_obtain_seed(gchar *seedfilename, const GString *passwd)
{
  GString *initial = NULL;
  GString *result = NULL;
  gchar *holder;
  unsigned char digest[40];

  initial = g_string_sized_new(512);
  result = g_string_sized_new(512);

  if (!log_signer_seed_buffering(initial, seedfilename))
  {
    msg_error("Error opening initialization key file",
        evt_tag_str(EVT_TAG_FILENAME, seedfilename),
        evt_tag_errno(EVT_TAG_OSERROR, errno),
        NULL);
    return NULL;
  }
  result = log_signer_AES_ecb_encrypt(initial, passwd, AES_DECRYPT);

  compute_sha1(result, (char *)digest);
  g_string_erase(result, 0, -1);
  g_string_assign(result, (gchar *) digest);
  result->len = strlen((char *)digest);

  memset(digest, '\0', sizeof(digest));
  g_string_free(initial, TRUE);
  holder = result->str;
  g_string_free(result, TRUE);

  return holder;
}

gboolean log_signer_verify(GlobalConfig *cfg, GString *entry, GString *stamp, GString *key)
{
  gchar buf[256];
  GString *macbuf  = NULL;
  macbuf = g_string_sized_new(SHA1_MAC_SIZE);
  gboolean valid;

  cfg->hash_func(key, (char *) buf);
  g_string_assign(key, buf);
  memset(buf, '\0', 256);
  compute_mac(entry, key, (char *) buf, cfg->hash_func_name);
  g_string_assign(macbuf, buf);
  memset(buf, '\0', 256);
  valid = g_string_equal(macbuf, stamp);
  g_string_free(macbuf, TRUE);

  return valid;
}

gboolean log_signer_valid_log_scan(GlobalConfig *cfg, GString *filename, GString *pemac, GString *lemac)
{
  FILE *log;
  GString *entry  = NULL;
  GString *stamp  = NULL;

  gboolean intact = TRUE, msgbuf = TRUE;
  int c, nc;

  entry = g_string_sized_new(MAX_READ);
  stamp = g_string_sized_new(MAX(SHA1_MAC_SIZE, MD5_MAC_SIZE));

  log = fopen((char *) filename->str, "r");
  fseek(log, 0, SEEK_SET);

  while(1)
  {
    c = fgetc(log);
    if (c == EOF)
    {
      gchar buf[256];

      cfg->hash_func(pemac, (char *) buf);
      g_string_assign(pemac, buf);
      memset(buf, '\0', 256);

      if (!g_string_equal(pemac, lemac))
        intact = FALSE;
      break;
    }
    else if (c == '\t')
    {
      if ((nc = fgetc(log)) != '{')
      {
        g_string_append_c(entry, (gchar) c);
        fseek(log, -1, SEEK_CUR);
      }
      else
        msgbuf = FALSE;
    }
    else if (c == '\n')
    {
      msgbuf = TRUE;
      if (!log_signer_verify(cfg, entry, stamp, pemac))
      {
        intact = FALSE;
        break;
      }
    }
    else
      if (msgbuf)
        g_string_append_c(entry, (gchar) c);
      else
        if (c != '}')
          g_string_append_c(stamp, (gchar) c);
        else
          continue;
  }
  fclose(log);
  g_string_free(entry, TRUE);
  g_string_free(stamp, TRUE);
  return intact;
}

gsize log_signer_plain_buffering_method(GString *filename, GString *buffer)
{
  FILE *file;
  int c;

  file = fopen((char *) filename->str, "r");
  fseek(file, 0, SEEK_SET);
  while(TRUE)
  {
    c = fgetc(file);
    if (c == EOF)
      break;
    else
      g_string_append_c(buffer, (gchar) c);
  }

  fclose(file);

  return buffer->len;
}

void log_signer_init_key_generator(GString *filename, GString *init_key)
{
  struct sha1_ctx temp_sha1_ctx;
  unsigned char digest[20];
  int i;

  sha1_init_ctx(&temp_sha1_ctx);
  sha1_process_bytes((unsigned char *) interactive->seed, strlen((char *) interactive->seed), &temp_sha1_ctx);
  sha1_process_bytes((unsigned char *) filename->str, filename->len, &temp_sha1_ctx);
  sha1_finish_ctx(&temp_sha1_ctx, digest);

  for(i = 0; i < sizeof(digest); i++)
    sprintf(init_key->str + i*2, "%.2hhx", digest[i]);
  init_key->len = i * 2;
  memset(digest, 0, sizeof(digest));
}

void log_signer_get_last_entry_key(GString *last_entry_key, gchar *path)
{
  GString *last_key_file = NULL;
  GString *last_entry_key_encrypted = NULL;
  GString *temp = NULL;

  last_key_file = g_string_sized_new(256);
  last_entry_key_encrypted = g_string_sized_new(64);
  last_key_file->str = g_strconcat(path, ".lastkey", NULL);
  last_entry_key_encrypted->len = log_signer_plain_buffering_method(last_key_file, last_entry_key_encrypted);

  temp = log_signer_AES_ecb_encrypt(last_entry_key_encrypted, interactive->passwd, AES_DECRYPT);

  g_string_free(last_key_file, TRUE);
  g_string_free(last_entry_key_encrypted, TRUE);
  g_string_assign(last_entry_key, temp->str);
}

gboolean log_signer_last_key_file_creator(LogTransport *transport)
{
  GString *result = NULL;
  int fd, flags;
  mode_t mode;
  gssize rc;
  gchar *last_key_file = g_strconcat(transport->filename->str, ".lastkey", NULL);

  flags = O_WRONLY | O_CREAT | O_TRUNC | O_APPEND;
  mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

  if ((fd = open( (char *) last_key_file, flags, mode) ) == -1)
    msg_error("Error opening file for writing",
        evt_tag_str("filename", last_key_file),
        evt_tag_errno(EVT_TAG_OSERROR, errno),
        NULL);

  result = g_string_sized_new(512);
  result = log_signer_AES_ecb_encrypt(transport->lemac, interactive->passwd, AES_ENCRYPT);
  rc = write(fd, result->str, result->len);
  close(fd);
  g_free(last_key_file);

  if (rc != result->len)
    return FALSE;

  return TRUE;
}

void log_signer_cfg_refresh(GlobalConfig *cfg)
{
#if 0
  if ((cfg->seed = g_malloc0(KDF_SIZE)) && (interactive->seed = g_malloc0(KDF_SIZE)))
  {
    g_strlcpy(interactive->seed, log_signer_obtain_seed(cfg->initkey_file, interactive->passwd), KDF_SIZE + 1);
    cfg->seed = g_strdup(interactive->seed);
  }
#endif
  if ((interactive->seed = g_malloc0(KDF_SIZE)))
    g_strlcpy(interactive->seed, log_signer_obtain_seed(cfg->initkey_file, interactive->passwd), KDF_SIZE + 1);
  else
    msg_error("Error allocating memory",
        evt_tag_errno(EVT_TAG_OSERROR, errno),
        NULL);
}

gboolean log_signer_verify_syntax(char *line, char **macpos)
{
  size_t line_len, mac_len;
  char *trav;
  gboolean mac_ok = FALSE;

  line_len = strlen(line);
  mac_len = line_len;

  if (line[line_len - 1] != '}')
    return FALSE;
  else
    *(line + line_len - 1) = 0;

  trav = &line[line_len - 2];

  mac_len--;
  while(trav > line)
  {
    if (*trav == '{')
    {
      if ((&line[line_len-1] - trav - 1) >= 32)
      {
        *macpos = trav + 1;
        mac_ok = TRUE;
        break;
      }
      else
        return FALSE;
    }

    if (!((*trav >= 'a' && *trav <= 'f') || ((*trav >= '0' && *trav <= '9'))))
      return FALSE;

    mac_len--;
    trav--;
  }

  if (!mac_ok)
    return FALSE;

  trav--;
  mac_len--;
  if (*trav != '\t')
    return FALSE;

  if ((trav - line) < 3)
    return FALSE;

  *(line + mac_len - 1) = 0;

  return TRUE;
}

gboolean log_signer_malformed_log(GlobalConfig *cfg, FILE *log, GString *filename, int *lineno, GString *key, GString *last_key)
{
  gboolean checkll = FALSE;
  *lineno = 0;
  fseek(log, 0, SEEK_SET);
  while(!feof(log))
  {
    gchar *p, *eol, *macptr;
    gchar line[1024];

    p = fgets(line, sizeof(line), log);
    (*lineno)++;

    if (!p)
    {
      p = line;
      checkll = TRUE;
    }
    if (eol = strchr(p, '\n'))
      *eol = 0;
    if (!checkll) /*!feof(log) - originally*/
    {
      if (!log_signer_verify_syntax(p, &macptr))
        return TRUE;
      else
      {
        GString *entry = NULL;
        GString *mac = NULL;

        entry = g_string_sized_new(960);
        mac = g_string_sized_new(64);

        g_string_assign(entry, (gchar *) p);
        g_string_assign(mac, (gchar *) macptr);

        if (!log_signer_verify(cfg, entry, mac, key))
        {
          msg_error("Error verifying log file",
              evt_tag_str(EVT_TAG_FILENAME, filename->str),
              NULL);
          return TRUE;
        }
      }
    }
    else
    {
      char buf[256];

      cfg->hash_func(key, (char *) buf);
      g_string_assign(key, buf);
      memset(buf, '\0', 256);
      if (!g_string_equal(key, last_key))
      {
        msg_error("Error verifying the end of log file",
            evt_tag_str(EVT_TAG_FILENAME, filename->str),
            NULL);
        return TRUE;
      }
    }
  }
  return FALSE;
}

