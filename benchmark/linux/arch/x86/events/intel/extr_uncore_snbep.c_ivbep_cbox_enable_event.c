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
typedef  int u64 ;
struct hw_perf_event_extra {scalar_t__ idx; scalar_t__ reg; } ;
struct hw_perf_event {int config; scalar_t__ config_base; struct hw_perf_event_extra extra_reg; } ;
struct perf_event {struct hw_perf_event hw; } ;
struct intel_uncore_box {int dummy; } ;

/* Variables and functions */
 scalar_t__ EXTRA_REG_NONE ; 
 int SNBEP_PMON_CTL_EN ; 
 int uncore_shared_reg_config (struct intel_uncore_box*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wrmsrl (scalar_t__,int) ; 

__attribute__((used)) static void ivbep_cbox_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;
	struct hw_perf_event_extra *reg1 = &hwc->extra_reg;

	if (reg1->idx != EXTRA_REG_NONE) {
		u64 filter = uncore_shared_reg_config(box, 0);
		wrmsrl(reg1->reg, filter & 0xffffffff);
		wrmsrl(reg1->reg + 6, filter >> 32);
	}

	wrmsrl(hwc->config_base, hwc->config | SNBEP_PMON_CTL_EN);
}