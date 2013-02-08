/**
 * This codes comes from RFC 2104, and was just 
 * cleaned up and fitted to our needs.
 */

#include <string.h>
#include "md5.h"
#include "hmac-md5.h"

  void 
hmac_md5 (const void *msg, size_t msg_len, const void *key, size_t key_len, void *digest)
{
  struct md5_ctx ctx;
  /* inner padding - key XORd with ipad 
   * outer padding - key XORd with opad */
  unsigned char k_ipad[65], k_opad[65];
  int i;

  /* if key is longer than 64 bytes reset it to key=MD5(key) */
  if (key_len > 64) 
  {
    struct md5_ctx tmp_ctx;
    char tk[16];

    md5_init_ctx(&tmp_ctx);
    md5_process_bytes(key, key_len, &tmp_ctx);
    md5_finish_ctx(&tmp_ctx, tk);

    key     = tk;
    key_len = 16;
  }

  memset (k_ipad, '\0', sizeof (k_ipad));
  memset (k_opad, '\0', sizeof (k_opad));
  memcpy (k_ipad, key, key_len);
  memcpy (k_opad, key, key_len);

  /* XOR key with ipad and opad values */
  for (i = 0; i < 64; i++) {
    k_ipad[i] ^= 0x36;
    k_opad[i] ^= 0x5c;
  }

  /* perform inner MD5 */
  md5_init_ctx(&ctx);				/* init context for 1st pass */
  md5_process_bytes(k_ipad, 64, &ctx);		/* start with inner pad */
  md5_process_bytes(msg, msg_len, &ctx);	/* then text of datagram */
  md5_finish_ctx(&ctx, digest);			/* finish up 1st pass */

  /* perform outer MD5 */
  md5_init_ctx(&ctx);				/* init context for 1st pass */
  md5_process_bytes(k_opad, 64, &ctx);		/* start with outer pad */
  md5_process_bytes(digest, 16, &ctx);		/* then results of the 1st hash */
  md5_finish_ctx(&ctx, digest);			/* finish up 2st pass */
}
