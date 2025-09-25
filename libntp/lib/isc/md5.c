/*
 * FIPS 140-2 COMPLIANCE MODIFICATION:
 * This file has been completely disabled for FIPS compliance.
 * All MD5 functionality is replaced with stubs that will abort if called.
 */

#include "config.h"
#include <stdlib.h>

/* FIPS 140-2 COMPLIANCE: Minimal stub type definition */
typedef struct {
int fips_disabled;
} isc_md5_t;

/*
 * FIPS-compliant stub functions to prevent linking errors
 * These will cause runtime errors if called, indicating MD5 usage
 */
void isc_md5_init(isc_md5_t *ctx) {
/* MD5 disabled for FIPS compliance */
abort();
}

void isc_md5_update(isc_md5_t *ctx, const unsigned char *buf, unsigned int len) {
/* MD5 disabled for FIPS compliance */
abort();
}

void isc_md5_final(isc_md5_t *ctx, unsigned char *digest) {
/* MD5 disabled for FIPS compliance */
abort();
}

void isc_md5_invalidate(isc_md5_t *ctx) {
/* MD5 disabled for FIPS compliance */
abort();
}
