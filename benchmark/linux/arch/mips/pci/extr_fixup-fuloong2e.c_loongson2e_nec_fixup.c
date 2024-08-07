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
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int,unsigned int*) ; 
 int /*<<< orphan*/  pci_write_config_dword (struct pci_dev*,int,int) ; 

__attribute__((used)) static void loongson2e_nec_fixup(struct pci_dev *pdev)
{
	unsigned int val;

	/* Configures port 1, 2, 3, 4 to be validate*/
	pci_read_config_dword(pdev, 0xe0, &val);
	pci_write_config_dword(pdev, 0xe0, (val & ~7) | 0x4);

	/* System clock is 48-MHz Oscillator. */
	pci_write_config_dword(pdev, 0xe4, 1 << 5);
}