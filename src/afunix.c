/*
 * Copyright (c) 2002-2009 BalaBit IT Ltd, Budapest, Hungary
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
  
#include "afunix.h"
#include "misc.h"
#include "messages.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <unistd.h>

void 
afunix_sd_set_uid(LogDriver *s, gchar *owner)
{
  AFUnixSourceDriver *self = (AFUnixSourceDriver *) s;
  
  if (!resolve_user(owner, &self->owner))
    msg_error("Error resolving username", 
              evt_tag_str("owner", owner),
              NULL);
}

void 
afunix_sd_set_gid(LogDriver *s, gchar *group)
{
  AFUnixSourceDriver *self = (AFUnixSourceDriver *) s;

  if (!resolve_group(group, &self->group))
    msg_error("Error resolving group",
              evt_tag_str("group", group),
              NULL);
}

void 
afunix_sd_set_perm(LogDriver *s, mode_t perm)
{
  AFUnixSourceDriver *self = (AFUnixSourceDriver *) s;

  self->perm = perm & 0777;
}

static gboolean
afunix_sd_init(LogPipe *s)
{
  AFUnixSourceDriver *self = (AFUnixSourceDriver *) s;
  
  if (afsocket_sd_init(s))
    {
      /* change ownership separately, as chgrp may succeed while chown may not */
      if (self->owner >= 0)
        chown(self->filename, (uid_t) self->owner, -1);
      if (self->group >= 0)
        chown(self->filename, -1, (gid_t) self->group);
      if (self->perm >= 0)
        chmod(self->filename, (mode_t) self->perm);
      return TRUE;
    }
  return FALSE;
}

static void 
afunix_sd_free(LogPipe *s)
{
  AFUnixSourceDriver *self = (AFUnixSourceDriver *) s;
  
  g_free(self->filename);
  afsocket_sd_free(s);
}

LogDriver *
afunix_sd_new(gchar *filename, guint32 flags)
{
  AFUnixSourceDriver *self = g_new0(AFUnixSourceDriver, 1);

  afsocket_sd_init_instance(&self->super, &self->sock_options, flags);
  if (self->super.flags & AFSOCKET_DGRAM)
    self->super.transport = g_strdup("unix-dgram");
  else if (self->super.flags & AFSOCKET_STREAM)
    self->super.transport = g_strdup("unix-stream");
  self->super.max_connections = 256;
  self->super.bind_addr = g_sockaddr_unix_new(filename);
  self->super.super.super.init = afunix_sd_init;
  self->super.super.super.free_fn = afunix_sd_free;
  self->filename = g_strdup(filename);
  self->owner = -1;
  self->group = -1;
  self->perm = 0666;
  return &self->super.super;
}

LogDriver *
afunix_dd_new(gchar *filename, guint flags)
{
  AFUnixDestDriver *self = g_new0(AFUnixDestDriver, 1);
  
  afsocket_dd_init_instance(&self->super, &self->sock_options, flags, g_strdup("localhost"), g_strdup_printf("localhost.afunix:%s", filename));
  if (self->super.flags & AFSOCKET_DGRAM)
    self->super.transport = g_strdup("unix-dgram");
  else if (self->super.flags & AFSOCKET_STREAM)
    self->super.transport = g_strdup("unix-stream");
  self->super.bind_addr = g_sockaddr_unix_new(NULL);
  self->super.dest_addr = g_sockaddr_unix_new(filename);
  return &self->super.super;
}
