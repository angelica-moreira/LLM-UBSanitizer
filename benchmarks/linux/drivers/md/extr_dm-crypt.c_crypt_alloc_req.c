#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct crypt_config {int dummy; } ;
struct convert_context {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  crypt_alloc_req_aead (struct crypt_config*,struct convert_context*) ; 
 int /*<<< orphan*/  crypt_alloc_req_skcipher (struct crypt_config*,struct convert_context*) ; 
 scalar_t__ crypt_integrity_aead (struct crypt_config*) ; 

__attribute__((used)) static void crypt_alloc_req(struct crypt_config *cc,
			    struct convert_context *ctx)
{
	if (crypt_integrity_aead(cc))
		crypt_alloc_req_aead(cc, ctx);
	else
		crypt_alloc_req_skcipher(cc, ctx);
}