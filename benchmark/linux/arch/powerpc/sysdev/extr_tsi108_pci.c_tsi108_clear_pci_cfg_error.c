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
 int /*<<< orphan*/  tsi108_clear_pci_error (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tsi108_pci_cfg_phys ; 

void tsi108_clear_pci_cfg_error(void)
{
	tsi108_clear_pci_error(tsi108_pci_cfg_phys);
}