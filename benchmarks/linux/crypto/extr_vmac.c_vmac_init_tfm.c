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
struct vmac_tfm_ctx {struct crypto_cipher* cipher; } ;
struct crypto_tfm {int dummy; } ;
struct crypto_spawn {int dummy; } ;
struct crypto_instance {int dummy; } ;
struct crypto_cipher {int dummy; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct crypto_cipher*) ; 
 int PTR_ERR (struct crypto_cipher*) ; 
 struct crypto_spawn* crypto_instance_ctx (struct crypto_instance*) ; 
 struct crypto_cipher* crypto_spawn_cipher (struct crypto_spawn*) ; 
 struct crypto_instance* crypto_tfm_alg_instance (struct crypto_tfm*) ; 
 struct vmac_tfm_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static int vmac_init_tfm(struct crypto_tfm *tfm)
{
	struct crypto_instance *inst = crypto_tfm_alg_instance(tfm);
	struct crypto_spawn *spawn = crypto_instance_ctx(inst);
	struct vmac_tfm_ctx *tctx = crypto_tfm_ctx(tfm);
	struct crypto_cipher *cipher;

	cipher = crypto_spawn_cipher(spawn);
	if (IS_ERR(cipher))
		return PTR_ERR(cipher);

	tctx->cipher = cipher;
	return 0;
}