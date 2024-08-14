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
struct skcipher_alg {int dummy; } ;

/* Variables and functions */
 int crypto_register_skcipher (struct skcipher_alg*) ; 
 int /*<<< orphan*/  crypto_unregister_skcipher (struct skcipher_alg*) ; 

int crypto_register_skciphers(struct skcipher_alg *algs, int count)
{
	int i, ret;

	for (i = 0; i < count; i++) {
		ret = crypto_register_skcipher(&algs[i]);
		if (ret)
			goto err;
	}

	return 0;

err:
	for (--i; i >= 0; --i)
		crypto_unregister_skcipher(&algs[i]);

	return ret;
}