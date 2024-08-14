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
struct cc_aead_ctx {int /*<<< orphan*/  drvdata; } ;

/* Variables and functions */
 unsigned int cc_get_default_hash_len (int /*<<< orphan*/ ) ; 
 struct cc_aead_ctx* crypto_aead_ctx (struct crypto_aead*) ; 

__attribute__((used)) static unsigned int cc_get_aead_hash_len(struct crypto_aead *tfm)
{
	struct cc_aead_ctx *ctx = crypto_aead_ctx(tfm);

	return cc_get_default_hash_len(ctx->drvdata);
}