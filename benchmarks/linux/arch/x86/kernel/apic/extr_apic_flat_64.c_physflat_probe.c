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
 int /*<<< orphan*/ * apic ; 
 int /*<<< orphan*/  apic_physflat ; 
 scalar_t__ jailhouse_paravirt () ; 
 int num_possible_cpus () ; 

__attribute__((used)) static int physflat_probe(void)
{
	if (apic == &apic_physflat || num_possible_cpus() > 8 ||
	    jailhouse_paravirt())
		return 1;

	return 0;
}