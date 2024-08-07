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
struct s5p_mfc_ctx {int int_cond; unsigned int int_type; unsigned int int_err; int /*<<< orphan*/  queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void wake_up_ctx(struct s5p_mfc_ctx *ctx, unsigned int reason,
			unsigned int err)
{
	ctx->int_cond = 1;
	ctx->int_type = reason;
	ctx->int_err = err;
	wake_up(&ctx->queue);
}