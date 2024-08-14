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
struct aead_alg {int dummy; } ;

/* Variables and functions */
 int crypto_register_aead (struct aead_alg*) ; 
 int /*<<< orphan*/  crypto_unregister_aead (struct aead_alg*) ; 

int crypto_register_aeads(struct aead_alg *algs, int count)
{
	int i, ret;

	for (i = 0; i < count; i++) {
		ret = crypto_register_aead(&algs[i]);
		if (ret)
			goto err;
	}

	return 0;

err:
	for (--i; i >= 0; --i)
		crypto_unregister_aead(&algs[i]);

	return ret;
}