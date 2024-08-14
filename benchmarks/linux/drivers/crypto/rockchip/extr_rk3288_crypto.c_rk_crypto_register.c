#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct rk_crypto_info {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  hash; int /*<<< orphan*/  crypto; } ;
struct TYPE_5__ {scalar_t__ type; TYPE_1__ alg; struct rk_crypto_info* dev; } ;

/* Variables and functions */
 scalar_t__ ALG_TYPE_CIPHER ; 
 unsigned int ARRAY_SIZE (TYPE_2__**) ; 
 int crypto_register_ahash (int /*<<< orphan*/ *) ; 
 int crypto_register_alg (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_unregister_ahash (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_unregister_alg (int /*<<< orphan*/ *) ; 
 TYPE_2__** rk_cipher_algs ; 

__attribute__((used)) static int rk_crypto_register(struct rk_crypto_info *crypto_info)
{
	unsigned int i, k;
	int err = 0;

	for (i = 0; i < ARRAY_SIZE(rk_cipher_algs); i++) {
		rk_cipher_algs[i]->dev = crypto_info;
		if (rk_cipher_algs[i]->type == ALG_TYPE_CIPHER)
			err = crypto_register_alg(
					&rk_cipher_algs[i]->alg.crypto);
		else
			err = crypto_register_ahash(
					&rk_cipher_algs[i]->alg.hash);
		if (err)
			goto err_cipher_algs;
	}
	return 0;

err_cipher_algs:
	for (k = 0; k < i; k++) {
		if (rk_cipher_algs[i]->type == ALG_TYPE_CIPHER)
			crypto_unregister_alg(&rk_cipher_algs[k]->alg.crypto);
		else
			crypto_unregister_ahash(&rk_cipher_algs[i]->alg.hash);
	}
	return err;
}