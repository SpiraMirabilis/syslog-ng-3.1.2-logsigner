/**
 * hmac_md5.h
 * Function prototype is based on RFC 2104
 */

#ifndef HMAC_MD5_H
# define HMAC_MD5_H 1

#include <stddef.h>

extern void hmac_md5 (const void *msg, size_t msg_len, const void *key,
    size_t key_len, void *digest);

#endif /* HMAC_MD5_H */
