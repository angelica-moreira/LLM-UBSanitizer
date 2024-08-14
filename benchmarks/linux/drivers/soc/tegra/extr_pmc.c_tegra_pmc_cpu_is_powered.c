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
 int /*<<< orphan*/  pmc ; 
 int tegra_get_cpu_powergate_id (int /*<<< orphan*/ ,unsigned int) ; 
 int tegra_powergate_is_powered (int /*<<< orphan*/ ,int) ; 

bool tegra_pmc_cpu_is_powered(unsigned int cpuid)
{
	int id;

	id = tegra_get_cpu_powergate_id(pmc, cpuid);
	if (id < 0)
		return false;

	return tegra_powergate_is_powered(pmc, id);
}