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
struct pmu_hw_events {int /*<<< orphan*/  pmu_lock; } ;
struct hw_perf_event {int idx; } ;
struct perf_event {int /*<<< orphan*/  pmu; struct hw_perf_event hw; } ;
struct nds32_pmu {struct pmu_hw_events* (* get_hw_events ) () ;} ;

/* Variables and functions */
 int /*<<< orphan*/  nds32_pfm_counter_valid (struct nds32_pmu*,int) ; 
 int /*<<< orphan*/  nds32_pfm_disable_counter (int) ; 
 int /*<<< orphan*/  nds32_pfm_disable_intens (int) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct pmu_hw_events* stub1 () ; 
 struct nds32_pmu* to_nds32_pmu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nds32_pmu_disable_event(struct perf_event *event)
{
	unsigned long flags;
	struct hw_perf_event *hwc = &event->hw;
	struct nds32_pmu *cpu_pmu = to_nds32_pmu(event->pmu);
	struct pmu_hw_events *events = cpu_pmu->get_hw_events();
	int idx = hwc->idx;

	if (!nds32_pfm_counter_valid(cpu_pmu, idx)) {
		pr_err("CPU disabling wrong pfm counter IRQ enable %d\n", idx);
		return;
	}

	/*
	 * Disable counter and interrupt
	 */
	raw_spin_lock_irqsave(&events->pmu_lock, flags);

	/*
	 * Disable counter
	 */
	nds32_pfm_disable_counter(idx);

	/*
	 * Disable interrupt for this counter
	 */
	nds32_pfm_disable_intens(idx);

	raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}