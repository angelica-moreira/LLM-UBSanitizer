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
struct crypto_aead {int dummy; } ;

/* Variables and functions */
 int crypto_gcm_check_authsize (unsigned int) ; 

__attribute__((used)) static int safexcel_aead_gcm_setauthsize(struct crypto_aead *tfm,
					 unsigned int authsize)
{
	return crypto_gcm_check_authsize(authsize);
}