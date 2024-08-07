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
 int /*<<< orphan*/  SNBEP_CPUNODEID ; 
 int /*<<< orphan*/  SNBEP_GIDNIDMAP ; 
 int snbep_pci2phy_map_init (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snbep_pci_uncores ; 
 int /*<<< orphan*/  snbep_uncore_pci_driver ; 
 int /*<<< orphan*/ * uncore_pci_driver ; 
 int /*<<< orphan*/  uncore_pci_uncores ; 

int snbep_uncore_pci_init(void)
{
	int ret = snbep_pci2phy_map_init(0x3ce0, SNBEP_CPUNODEID, SNBEP_GIDNIDMAP, true);
	if (ret)
		return ret;
	uncore_pci_uncores = snbep_pci_uncores;
	uncore_pci_driver = &snbep_uncore_pci_driver;
	return 0;
}