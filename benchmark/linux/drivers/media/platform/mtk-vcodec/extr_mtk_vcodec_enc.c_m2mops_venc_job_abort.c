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
struct mtk_vcodec_ctx {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  MTK_STATE_ABORT ; 

__attribute__((used)) static void m2mops_venc_job_abort(void *priv)
{
	struct mtk_vcodec_ctx *ctx = priv;

	ctx->state = MTK_STATE_ABORT;
}