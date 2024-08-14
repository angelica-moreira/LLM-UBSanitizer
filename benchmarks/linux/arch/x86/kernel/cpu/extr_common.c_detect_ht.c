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
struct cpuinfo_x86 {int phys_proc_id; int x86_max_cores; int cpu_core_id; int /*<<< orphan*/  initial_apicid; } ;
struct TYPE_2__ {int (* phys_pkg_id ) (int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 TYPE_1__* apic ; 
 scalar_t__ detect_ht_early (struct cpuinfo_x86*) ; 
 int get_count_order (int) ; 
 int smp_num_siblings ; 
 int stub1 (int /*<<< orphan*/ ,int) ; 
 int stub2 (int /*<<< orphan*/ ,int) ; 

void detect_ht(struct cpuinfo_x86 *c)
{
#ifdef CONFIG_SMP
	int index_msb, core_bits;

	if (detect_ht_early(c) < 0)
		return;

	index_msb = get_count_order(smp_num_siblings);
	c->phys_proc_id = apic->phys_pkg_id(c->initial_apicid, index_msb);

	smp_num_siblings = smp_num_siblings / c->x86_max_cores;

	index_msb = get_count_order(smp_num_siblings);

	core_bits = get_count_order(c->x86_max_cores);

	c->cpu_core_id = apic->phys_pkg_id(c->initial_apicid, index_msb) &
				       ((1 << core_bits) - 1);
#endif
}