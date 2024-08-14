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
struct tegra_bpmp_channel {int /*<<< orphan*/ * ob; int /*<<< orphan*/  ivc; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (void*) ; 
 void* tegra_ivc_write_get_next_frame (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool tegra186_bpmp_is_channel_free(struct tegra_bpmp_channel *channel)
{
	void *frame;

	frame = tegra_ivc_write_get_next_frame(channel->ivc);
	if (IS_ERR(frame)) {
		channel->ob = NULL;
		return false;
	}

	channel->ob = frame;

	return true;
}