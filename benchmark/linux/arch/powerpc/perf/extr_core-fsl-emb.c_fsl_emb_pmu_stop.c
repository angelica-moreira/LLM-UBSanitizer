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
struct TYPE_2__ {scalar_t__ idx; int state; int /*<<< orphan*/  sample_period; } ;
struct perf_event {int /*<<< orphan*/  pmu; TYPE_1__ hw; } ;

/* Variables and functions */
 int PERF_HES_STOPPED ; 
 int PERF_HES_UPTODATE ; 
 int /*<<< orphan*/  fsl_emb_pmu_read (struct perf_event*) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  perf_event_update_userpage (struct perf_event*) ; 
 int /*<<< orphan*/  perf_pmu_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  perf_pmu_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_pmc (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fsl_emb_pmu_stop(struct perf_event *event, int ef_flags)
{
	unsigned long flags;

	if (event->hw.idx < 0 || !event->hw.sample_period)
		return;

	if (event->hw.state & PERF_HES_STOPPED)
		return;

	local_irq_save(flags);
	perf_pmu_disable(event->pmu);

	fsl_emb_pmu_read(event);
	event->hw.state |= PERF_HES_STOPPED | PERF_HES_UPTODATE;
	write_pmc(event->hw.idx, 0);

	perf_event_update_userpage(event);
	perf_pmu_enable(event->pmu);
	local_irq_restore(flags);
}