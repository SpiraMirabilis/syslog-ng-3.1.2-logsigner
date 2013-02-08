/*
 * Copyright (c) 2012 Christos Tsopokis, Dimitris Glynos, Athens, Greece
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

#ifndef LOG_SIGNER_H_INCLUDED

#define LOG_SIGNER_H_INCLUDED

#include "sha1.h"
#include "md5.h"
#include "hmac-md5.h"
#include "hmac-sha1.h"
#include "memxor.h"
#include "cfg.h"
#include "logtransport.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

/* bytes produced by each hash */
#define SHA1_SIZE		40
#define MD5_SIZE		32
#define KDF_SIZE		40

/* binary size of each produced hash */
#define SHA1_BIN_SIZE	20
#define MD5_BIN_SIZE	16

/* bytes produced by each mac function */
#define SHA1_MAC_SIZE	40
#define MD5_MAC_SIZE	32 
#define MAX_MAC max(SHA1_MAC_SIZE, MD5_MAC_SIZE)
#define MAX_READ      512
#define AES_BLOCK_SIZE 16

#define max(m,n) ((m) > (n) ? (m) : (n))
#define min(m,n) ((m) < (n) ? (m) : (n))

/* hash function options */
typedef enum
{
  LS_HFO_SHA1,
  LS_HFO_MD5,
} HashFunc;

void compute_md5(const GString *data, char *md5str);

void compute_sha1(const GString *data, char *sha1str);

void compute_mac(GString *msg, GString *key, char *macstr, int flag);

int blocks(gsize len);

void log_signer_kdf(GString *plain_passwd, GString *passwd);

GString *log_signer_AES_ecb_encrypt(GString *initial, const GString *key, const int mode);

GString *log_signer_passwd_retriever();

gchar *log_signer_obtain_seed(gchar *seedfilename, const GString *passwd);

gboolean log_signer_seed_buffering(GString *seedbuf, gchar *filename);

gboolean log_signer_verify(GlobalConfig *cfg, GString *entry, GString *stamp, GString *key);

gboolean log_signer_valid_log_scan(GlobalConfig *cfg, GString *filename, GString *femac, GString *lemac);

gsize log_signer_plain_buffering_method(GString *filename, GString *buffer);

void log_signer_init_key_generator(GString *filename, GString *init_key);

void log_signer_get_last_entry_key(GString *last_entry_key, gchar *path);

gboolean log_signer_last_key_file_creator(LogTransport *transport);

void log_signer_cfg_refresh(GlobalConfig *cfg);

gboolean log_signer_verify_syntax(char *line, char **macpos);

gboolean log_signer_malformed_log(GlobalConfig *cfg, FILE *log, GString *filename, int *lineno, GString *key, GString *last_key);

#endif

