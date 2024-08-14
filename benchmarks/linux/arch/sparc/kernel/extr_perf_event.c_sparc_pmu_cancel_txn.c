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
struct pmu {int dummy; } ;
struct cpu_hw_events {unsigned int txn_flags; } ;

/* Variables and functions */
 unsigned int PERF_PMU_TXN_ADD ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  cpu_hw_events ; 
 int /*<<< orphan*/  perf_pmu_enable (struct pmu*) ; 
 struct cpu_hw_events* this_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sparc_pmu_cancel_txn(struct pmu *pmu)
{
	struct cpu_hw_events *cpuhw = this_cpu_ptr(&cpu_hw_events);
	unsigned int txn_flags;

	WARN_ON_ONCE(!cpuhw->txn_flags);	/* no txn in flight */

	txn_flags = cpuhw->txn_flags;
	cpuhw->txn_flags = 0;
	if (txn_flags & ~PERF_PMU_TXN_ADD)
		return;

	perf_pmu_enable(pmu);
}