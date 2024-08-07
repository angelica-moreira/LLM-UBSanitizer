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
struct TYPE_2__ {unsigned int frequency; } ;

/* Variables and functions */
 TYPE_1__* maple_cpu_freqs ; 
 size_t maple_pmode_cur ; 

__attribute__((used)) static unsigned int maple_cpufreq_get_speed(unsigned int cpu)
{
	return maple_cpu_freqs[maple_pmode_cur].frequency;
}