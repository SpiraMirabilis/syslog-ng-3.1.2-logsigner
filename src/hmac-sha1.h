/**
 * hmac_sha1.h
 * Function prototype is based on hmac.h as distributed by
 * Copyright (C) 2005 Free Software Foundation, Inc.
 */

#ifndef HMAC_SHA1_H
# define HMAC_SHA1_H 1

#include <stddef.h>

extern void hmac_sha1 (const void *msg, size_t msg_len, const void *key, 
    size_t key_len, void *digest);

#endif /* HMAC_SHA1_H */
