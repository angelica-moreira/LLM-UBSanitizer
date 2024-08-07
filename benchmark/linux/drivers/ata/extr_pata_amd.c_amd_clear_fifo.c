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
typedef  int u8 ;
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,int) ; 

__attribute__((used)) static void amd_clear_fifo(struct pci_dev *pdev)
{
	u8 fifo;
	/* Disable the FIFO, the FIFO logic will re-enable it as
	   appropriate */
	pci_read_config_byte(pdev, 0x41, &fifo);
	fifo &= 0x0F;
	pci_write_config_byte(pdev, 0x41, fifo);
}