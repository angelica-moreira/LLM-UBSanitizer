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
typedef  int u16 ;
struct pci_dev {int dummy; } ;
struct pci_cmd_info {int val; } ;

/* Variables and functions */
 int PCI_COMMAND_GUEST ; 
 int pci_read_config_word (struct pci_dev*,int,int*) ; 

__attribute__((used)) static int command_read(struct pci_dev *dev, int offset, u16 *value, void *data)
{
	int ret = pci_read_config_word(dev, offset, value);
	const struct pci_cmd_info *cmd = data;

	*value &= PCI_COMMAND_GUEST;
	*value |= cmd->val & ~PCI_COMMAND_GUEST;

	return ret;
}