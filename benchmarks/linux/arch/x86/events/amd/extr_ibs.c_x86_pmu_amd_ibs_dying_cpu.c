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

/* Variables and functions */
 int /*<<< orphan*/  clear_APIC_ibs () ; 

__attribute__((used)) static int x86_pmu_amd_ibs_dying_cpu(unsigned int cpu)
{
	clear_APIC_ibs();
	return 0;
}