/*
 * ntp_md5.h: MD5 support completely disabled for FIPS 140-2 compliance
 *
 * FIPS COMPLIANCE: All MD5 functionality removed
 */
#ifndef NTP_MD5_H
#define NTP_MD5_H

/* FIPS COMPLIANCE: MD5 completely disabled - no MD5 support whatsoever */

/* MD5auth function declarations removed - these functions no longer exist */
/* All MD5 functionality has been eliminated for FIPS 140-2 compliance */

#define KEY_TYPE_MD5		4	/* NID_md5 from openssl/objects.h */

#ifdef OPENSSL
# include <openssl/evp.h>
# include "libssl_compat.h"
# ifdef HAVE_OPENSSL_CMAC_H
#  include <openssl/cmac.h>
#  define CMAC                  "AES128CMAC"
#  define AES_128_KEY_SIZE      16
# endif /*HAVE_OPENSSL_CMAC_H*/
#endif /* OPENSSL */

/* No MD5 support - all MD5 functions removed */
/* Use only FIPS-approved algorithms: SHA-1, SHA-256, AES-CMAC */

#endif /* NTP_MD5_H */
