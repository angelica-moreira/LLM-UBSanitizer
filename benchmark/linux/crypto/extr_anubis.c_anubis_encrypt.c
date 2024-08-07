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
typedef  int /*<<< orphan*/  u8 ;
struct crypto_tfm {int dummy; } ;
struct anubis_ctx {int /*<<< orphan*/  R; int /*<<< orphan*/  E; } ;

/* Variables and functions */
 int /*<<< orphan*/  anubis_crypt (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 struct anubis_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static void anubis_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
	struct anubis_ctx *ctx = crypto_tfm_ctx(tfm);
	anubis_crypt(ctx->E, dst, src, ctx->R);
}