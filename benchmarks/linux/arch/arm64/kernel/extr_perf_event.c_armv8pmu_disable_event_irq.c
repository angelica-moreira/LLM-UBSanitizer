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
struct TYPE_2__ {int /*<<< orphan*/  idx; } ;
struct perf_event {TYPE_1__ hw; } ;

/* Variables and functions */
 int armv8pmu_disable_intens (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int armv8pmu_disable_event_irq(struct perf_event *event)
{
	return armv8pmu_disable_intens(event->hw.idx);
}