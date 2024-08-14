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
struct tegra_drm_context {int /*<<< orphan*/  channel; } ;

/* Variables and functions */
 int /*<<< orphan*/  host1x_channel_put (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void gr2d_close_channel(struct tegra_drm_context *context)
{
	host1x_channel_put(context->channel);
}