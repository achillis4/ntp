/*
 * Copyright (C) 2004-2007, 2009, 2010  Internet Systems Consortium, Inc. ("ISC")
 * Copyright (C) 2000, 2001  Internet Software Consortium.
 * 
 * FIPS 140-2 COMPLIANCE MODIFICATION:
 * This file has been modified to disable MD5 support for FIPS compliance.
 * All MD5 functionality is disabled and will cause program termination if used.
 */

#ifndef ISC_MD5_H
#define ISC_MD5_H 1

#include <isc/lang.h>
#include <isc/platform.h>
#include <isc/types.h>

#define ISC_MD5_DIGESTLENGTH 16U
#define ISC_MD5_BLOCK_LENGTH 64U

/* FIPS 140-2 COMPLIANCE: MD5 disabled - provide minimal stub type */
typedef struct {
	int fips_disabled;
} isc_md5_t;

ISC_LANG_BEGINDECLS

/* FIPS 140-2 COMPLIANCE: All MD5 functions disabled - stubs that will abort */
void isc_md5_init(isc_md5_t *ctx);
void isc_md5_invalidate(isc_md5_t *ctx);
void isc_md5_update(isc_md5_t *ctx, const unsigned char *buf, unsigned int len);
void isc_md5_final(isc_md5_t *ctx, unsigned char *digest);

ISC_LANG_ENDDECLS

#endif /* ISC_MD5_H */
