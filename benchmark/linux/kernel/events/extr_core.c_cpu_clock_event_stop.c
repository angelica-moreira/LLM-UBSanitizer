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
struct perf_event {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_clock_event_update (struct perf_event*) ; 
 int /*<<< orphan*/  perf_swevent_cancel_hrtimer (struct perf_event*) ; 

__attribute__((used)) static void cpu_clock_event_stop(struct perf_event *event, int flags)
{
	perf_swevent_cancel_hrtimer(event);
	cpu_clock_event_update(event);
}