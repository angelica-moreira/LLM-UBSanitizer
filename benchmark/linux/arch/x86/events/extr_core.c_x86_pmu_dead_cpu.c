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
struct TYPE_2__ {int /*<<< orphan*/  (* cpu_dead ) (unsigned int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (unsigned int) ; 
 TYPE_1__ x86_pmu ; 

__attribute__((used)) static int x86_pmu_dead_cpu(unsigned int cpu)
{
	if (x86_pmu.cpu_dead)
		x86_pmu.cpu_dead(cpu);
	return 0;
}