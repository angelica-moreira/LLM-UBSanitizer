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
 int find_acpi_cpu_topology_tag (unsigned int,int,int /*<<< orphan*/ ) ; 

int find_acpi_cpu_topology(unsigned int cpu, int level)
{
	return find_acpi_cpu_topology_tag(cpu, level, 0);
}