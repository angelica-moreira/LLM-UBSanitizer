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
 int /*<<< orphan*/  cpu_sibling_map ; 
 int cpumask_first (int /*<<< orphan*/ ) ; 
 int smp_processor_id () ; 
 int /*<<< orphan*/  this_cpu_cpumask_var_ptr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int get_stagger(void)
{
#ifdef CONFIG_SMP
	int cpu = smp_processor_id();
	return cpu != cpumask_first(this_cpu_cpumask_var_ptr(cpu_sibling_map));
#endif
	return 0;
}