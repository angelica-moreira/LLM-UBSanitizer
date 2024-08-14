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
struct hw_perf_event {scalar_t__ config_base; int /*<<< orphan*/  config; } ;
struct perf_event {struct hw_perf_event hw; } ;
struct intel_uncore_box {scalar_t__ io_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void snr_uncore_mmio_disable_event(struct intel_uncore_box *box,
					    struct perf_event *event)
{
	struct hw_perf_event *hwc = &event->hw;

	if (!box->io_addr)
		return;

	writel(hwc->config, box->io_addr + hwc->config_base);
}