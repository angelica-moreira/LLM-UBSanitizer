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
struct clocksource {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OMAP_TIMER_NONPOSTED ; 
 int /*<<< orphan*/  __omap_dm_timer_read_counter (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clksrc ; 
 int /*<<< orphan*/  clocksource_gpt_hwmod ; 
 int /*<<< orphan*/  omap2_gptimer_clksrc_load ; 
 int /*<<< orphan*/  omap_hwmod_idle (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void omap2_gptimer_clksrc_suspend(struct clocksource *unused)
{
	omap2_gptimer_clksrc_load =
		__omap_dm_timer_read_counter(&clksrc, OMAP_TIMER_NONPOSTED);

	omap_hwmod_idle(clocksource_gpt_hwmod);
}