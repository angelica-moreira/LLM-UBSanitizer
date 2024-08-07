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
struct sock {int dummy; } ;
struct crypto_ahash {int dummy; } ;

/* Variables and functions */
 int CRYPTO_TFM_NEED_KEY ; 
 int ENOKEY ; 
 int crypto_ahash_get_flags (struct crypto_ahash*) ; 
 int hash_accept_parent_nokey (void*,struct sock*) ; 

__attribute__((used)) static int hash_accept_parent(void *private, struct sock *sk)
{
	struct crypto_ahash *tfm = private;

	if (crypto_ahash_get_flags(tfm) & CRYPTO_TFM_NEED_KEY)
		return -ENOKEY;

	return hash_accept_parent_nokey(private, sk);
}