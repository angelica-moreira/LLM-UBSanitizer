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
typedef  int u32 ;
struct hw_perf_event {int idx; } ;
struct hisi_pmu {scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ L3C_INT_MASK ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void hisi_l3c_pmu_disable_counter_int(struct hisi_pmu *l3c_pmu,
					     struct hw_perf_event *hwc)
{
	u32 val;

	val = readl(l3c_pmu->base + L3C_INT_MASK);
	/* Write 1 to mask interrupt */
	val |= (1 << hwc->idx);
	writel(val, l3c_pmu->base + L3C_INT_MASK);
}