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
struct priv {int /*<<< orphan*/  child; scalar_t__ table; } ;
struct crypto_skcipher {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  crypto_free_skcipher (int /*<<< orphan*/ ) ; 
 struct priv* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 int /*<<< orphan*/  gf128mul_free_64k (scalar_t__) ; 

__attribute__((used)) static void exit_tfm(struct crypto_skcipher *tfm)
{
	struct priv *ctx = crypto_skcipher_ctx(tfm);

	if (ctx->table)
		gf128mul_free_64k(ctx->table);
	crypto_free_skcipher(ctx->child);
}