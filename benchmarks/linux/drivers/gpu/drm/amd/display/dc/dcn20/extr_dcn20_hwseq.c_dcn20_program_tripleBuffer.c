#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_3__* hubp; } ;
struct pipe_ctx {TYPE_2__ plane_res; } ;
struct dc {int dummy; } ;
struct TYPE_6__ {TYPE_1__* funcs; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* hubp_enable_tripleBuffer ) (TYPE_3__*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_3__*,int) ; 

void dcn20_program_tripleBuffer(
	const struct dc *dc,
	struct pipe_ctx *pipe_ctx,
	bool enableTripleBuffer)
{
	if (pipe_ctx->plane_res.hubp && pipe_ctx->plane_res.hubp->funcs) {
		pipe_ctx->plane_res.hubp->funcs->hubp_enable_tripleBuffer(
			pipe_ctx->plane_res.hubp,
			enableTripleBuffer);
	}
}