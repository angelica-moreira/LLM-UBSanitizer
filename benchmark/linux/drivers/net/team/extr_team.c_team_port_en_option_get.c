#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct team_port {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  bool_val; } ;
struct team_gsetter_ctx {TYPE_2__ data; TYPE_1__* info; } ;
struct team {int dummy; } ;
struct TYPE_3__ {struct team_port* port; } ;

/* Variables and functions */
 int /*<<< orphan*/  team_port_enabled (struct team_port*) ; 

__attribute__((used)) static int team_port_en_option_get(struct team *team,
				   struct team_gsetter_ctx *ctx)
{
	struct team_port *port = ctx->info->port;

	ctx->data.bool_val = team_port_enabled(port);
	return 0;
}