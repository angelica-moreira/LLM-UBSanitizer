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
struct pipe_ctx {struct pipe_ctx* bottom_pipe; TYPE_1__* plane_state; } ;
struct TYPE_2__ {scalar_t__ visible; } ;

/* Variables and functions */

bool is_lower_pipe_tree_visible(struct pipe_ctx *pipe_ctx)
{
	if (pipe_ctx->plane_state && pipe_ctx->plane_state->visible)
		return true;
	if (pipe_ctx->bottom_pipe && is_lower_pipe_tree_visible(pipe_ctx->bottom_pipe))
		return true;
	return false;
}