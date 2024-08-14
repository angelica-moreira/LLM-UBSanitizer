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
struct TYPE_2__ {int /*<<< orphan*/  state; } ;
struct perf_event {TYPE_1__ hw; } ;

/* Variables and functions */
 int PERF_EF_UPDATE ; 
 int /*<<< orphan*/  PERF_HES_STOPPED ; 
 int /*<<< orphan*/  i915_pmu_disable (struct perf_event*) ; 
 int /*<<< orphan*/  i915_pmu_event_read (struct perf_event*) ; 

__attribute__((used)) static void i915_pmu_event_stop(struct perf_event *event, int flags)
{
	if (flags & PERF_EF_UPDATE)
		i915_pmu_event_read(event);
	i915_pmu_disable(event);
	event->hw.state = PERF_HES_STOPPED;
}