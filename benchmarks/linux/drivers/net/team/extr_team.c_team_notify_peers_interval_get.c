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
struct TYPE_3__ {int /*<<< orphan*/  u32_val; } ;
struct team_gsetter_ctx {TYPE_1__ data; } ;
struct TYPE_4__ {int /*<<< orphan*/  interval; } ;
struct team {TYPE_2__ notify_peers; } ;

/* Variables and functions */

__attribute__((used)) static int team_notify_peers_interval_get(struct team *team,
					  struct team_gsetter_ctx *ctx)
{
	ctx->data.u32_val = team->notify_peers.interval;
	return 0;
}