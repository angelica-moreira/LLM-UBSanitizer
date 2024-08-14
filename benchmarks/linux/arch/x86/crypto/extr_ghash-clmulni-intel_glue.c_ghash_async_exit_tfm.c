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
struct ghash_async_ctx {int /*<<< orphan*/  cryptd_tfm; } ;
struct crypto_tfm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cryptd_free_ahash (int /*<<< orphan*/ ) ; 
 struct ghash_async_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static void ghash_async_exit_tfm(struct crypto_tfm *tfm)
{
	struct ghash_async_ctx *ctx = crypto_tfm_ctx(tfm);

	cryptd_free_ahash(ctx->cryptd_tfm);
}