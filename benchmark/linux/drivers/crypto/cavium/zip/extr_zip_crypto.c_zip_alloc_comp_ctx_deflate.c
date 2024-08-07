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
struct zip_kernel_ctx {int dummy; } ;
struct crypto_tfm {int dummy; } ;

/* Variables and functions */
 struct zip_kernel_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int zip_ctx_init (struct zip_kernel_ctx*,int /*<<< orphan*/ ) ; 

int zip_alloc_comp_ctx_deflate(struct crypto_tfm *tfm)
{
	int ret;
	struct zip_kernel_ctx *zip_ctx = crypto_tfm_ctx(tfm);

	ret = zip_ctx_init(zip_ctx, 0);

	return ret;
}