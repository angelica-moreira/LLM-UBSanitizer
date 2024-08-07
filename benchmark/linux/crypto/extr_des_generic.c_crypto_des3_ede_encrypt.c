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
struct des3_ede_ctx {int dummy; } ;
struct crypto_tfm {int dummy; } ;

/* Variables and functions */
 struct des3_ede_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  des3_ede_encrypt (struct des3_ede_ctx const*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static void crypto_des3_ede_encrypt(struct crypto_tfm *tfm, u8 *dst,
				    const u8 *src)
{
	const struct des3_ede_ctx *dctx = crypto_tfm_ctx(tfm);

	des3_ede_encrypt(dctx, dst, src);
}