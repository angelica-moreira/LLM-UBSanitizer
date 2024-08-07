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
struct hw_perf_event {int /*<<< orphan*/  config; int /*<<< orphan*/  config_base; } ;
struct perf_event {struct hw_perf_event hw; } ;

/* Variables and functions */
 int P4_CCCR_ENABLE ; 
 int P4_CCCR_OVF ; 
 int P4_CCCR_RESERVED ; 
 int p4_config_unpack_cccr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wrmsrl_safe (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void p4_pmu_disable_event(struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;

	/*
	 * If event gets disabled while counter is in overflowed
	 * state we need to clear P4_CCCR_OVF, otherwise interrupt get
	 * asserted again and again
	 */
	(void)wrmsrl_safe(hwc->config_base,
		p4_config_unpack_cccr(hwc->config) & ~P4_CCCR_ENABLE & ~P4_CCCR_OVF & ~P4_CCCR_RESERVED);
}