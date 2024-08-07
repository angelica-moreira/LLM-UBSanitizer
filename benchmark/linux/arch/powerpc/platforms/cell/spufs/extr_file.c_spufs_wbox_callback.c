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
struct spu_context {int /*<<< orphan*/  wbox_wq; } ;
struct spu {struct spu_context* ctx; } ;

/* Variables and functions */
 int /*<<< orphan*/  wake_up_all (int /*<<< orphan*/ *) ; 

void spufs_wbox_callback(struct spu *spu)
{
	struct spu_context *ctx = spu->ctx;

	if (ctx)
		wake_up_all(&ctx->wbox_wq);
}