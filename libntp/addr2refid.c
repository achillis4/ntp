/*
 * addr2refid.c - Convert IP address to NTP reference identifier
 *
 * FIPS COMPLIANCE: Replaces MD5 with SHA-256 for IPv6 addresses
 */

#include <config.h>

#include "ntp_stdlib.h"
#include "ntp_fp.h"
#include "ntp_string.h"
#include "ntp_md5.h"

#ifdef OPENSSL
# include <openssl/evp.h>
# include <openssl/objects.h>
# include <openssl/md5.h>
# include <openssl/sha.h>
#endif

/*
 * addr2refid - map an address to a reference ID.
 * For IPv4, simply return the address.  
 * For IPv6, return first 4 octets of SHA-256 hash (FIPS-compliant replacement for MD5)
 */
u_int32
addr2refid(sockaddr_u *addr)
{
#ifdef OPENSSL
	u_char		digest[EVP_MAX_MD_SIZE];
#else
	u_char		digest[32]; /* SHA-256 size */
#endif
	u_int32		addr_refid;
	EVP_MD_CTX	*ctx;
	u_int		len;

	if (IS_IPV4(addr))
		return (NSRCADR(addr));

#ifdef OPENSSL
	ctx = EVP_MD_CTX_new();
	if (ctx == NULL) {
		msyslog(LOG_ERR, "EVP_MD_CTX_new() failed");
		goto fallback;
	}

	/* Use SHA-256 instead of MD5 for FIPS compliance */
	if (!EVP_DigestInit_ex(ctx, EVP_sha256(), NULL)) {
		msyslog(LOG_ERR, "SHA-256 init failed");
		EVP_MD_CTX_free(ctx);
		goto fallback;
	}

	if (IS_IPV6(addr)) {
		EVP_DigestUpdate(ctx, (u_char *)PSOCK_ADDR6(addr),
		    sizeof(struct in6_addr));
	}

	EVP_DigestFinal_ex(ctx, digest, &len);
	EVP_MD_CTX_free(ctx);
	
	memcpy(&addr_refid, digest, sizeof(addr_refid));
	return (addr_refid);

fallback:
#endif /* OPENSSL */
	/* 
	 * Fallback without OpenSSL: use a simple hash of the address
	 * This is not as secure but provides basic functionality
	 */
	if (IS_IPV6(addr)) {
		struct in6_addr *in6 = &SOCK_ADDR6(addr);
		u_int32 hash = 0;
		int i;
		
		/* Simple XOR-based hash of IPv6 address */
		for (i = 0; i < 4; i++) {
			hash ^= ((u_int32*)in6)[i];
		}
		return hash;
	}
	
	/* Should not reach here for IPv4 */
	return 0;
}