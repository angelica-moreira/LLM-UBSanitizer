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
struct crypto_tfm {int dummy; } ;
struct aes_ctx {int dummy; } ;

/* Variables and functions */
 struct aes_ctx* aes_ctx_common (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static inline struct aes_ctx *aes_ctx(struct crypto_tfm *tfm)
{
	return aes_ctx_common(crypto_tfm_ctx(tfm));
}