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
struct perf_event {int dummy; } ;

/* Variables and functions */
 scalar_t__ atomic_dec_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  release_pmc_hardware () ; 
 int /*<<< orphan*/  riscv_active_events ; 

__attribute__((used)) static void riscv_event_destroy(struct perf_event *event)
{
	if (atomic_dec_return(&riscv_active_events) == 0)
		release_pmc_hardware();
}