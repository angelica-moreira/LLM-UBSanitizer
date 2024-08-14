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
struct dc_log_buffer_ctx {int dummy; } ;
struct dc_context {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dm_dtn_log_append_v (struct dc_context*,struct dc_log_buffer_ctx*,char*,char const*) ; 
 int /*<<< orphan*/  pr_info (char*,char const*) ; 

void dm_dtn_log_end(struct dc_context *ctx,
	struct dc_log_buffer_ctx *log_ctx)
{
	static const char msg[] = "[dtn end]\n";

	if (!log_ctx) {
		pr_info("%s", msg);
		return;
	}

	dm_dtn_log_append_v(ctx, log_ctx, "%s", msg);
}