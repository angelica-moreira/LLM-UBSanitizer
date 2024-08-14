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
struct TYPE_2__ {int idx; unsigned long long last_tag; } ;
struct perf_event {TYPE_1__ hw; } ;
struct intel_uncore_box {int n_events; struct perf_event** event_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  PERF_EF_UPDATE ; 
 struct intel_uncore_box* uncore_event_to_box (struct perf_event*) ; 
 scalar_t__ uncore_pmc_freerunning (int) ; 
 int /*<<< orphan*/  uncore_pmu_event_stop (struct perf_event*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uncore_put_event_constraint (struct intel_uncore_box*,struct perf_event*) ; 

void uncore_pmu_event_del(struct perf_event *event, int flags)
{
	struct intel_uncore_box *box = uncore_event_to_box(event);
	int i;

	uncore_pmu_event_stop(event, PERF_EF_UPDATE);

	/*
	 * The event for free running counter is not tracked by event_list.
	 * It doesn't need to force event->hw.idx = -1 to reassign the counter.
	 * Because the event and the free running counter are 1:1 mapped.
	 */
	if (uncore_pmc_freerunning(event->hw.idx))
		return;

	for (i = 0; i < box->n_events; i++) {
		if (event == box->event_list[i]) {
			uncore_put_event_constraint(box, event);

			for (++i; i < box->n_events; i++)
				box->event_list[i - 1] = box->event_list[i];

			--box->n_events;
			break;
		}
	}

	event->hw.idx = -1;
	event->hw.last_tag = ~0ULL;
}