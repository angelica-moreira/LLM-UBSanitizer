#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct hmac_ctx {int dummy; } ;
struct chcr_context {TYPE_1__* crypto_ctx; } ;
struct TYPE_2__ {struct hmac_ctx* hmacctx; } ;

/* Variables and functions */

__attribute__((used)) static inline struct hmac_ctx *HMAC_CTX(struct chcr_context *ctx)
{
	return ctx->crypto_ctx->hmacctx;
}