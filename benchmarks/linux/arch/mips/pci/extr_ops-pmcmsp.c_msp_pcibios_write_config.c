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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct pci_bus {int dummy; } ;

/* Variables and functions */
 int PCIBIOS_SUCCESSFUL ; 
 scalar_t__ msp_pcibios_write_config_byte (struct pci_bus*,unsigned int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ msp_pcibios_write_config_dword (struct pci_bus*,unsigned int,int,int) ; 
 scalar_t__ msp_pcibios_write_config_word (struct pci_bus*,unsigned int,int,int /*<<< orphan*/ ) ; 

int
msp_pcibios_write_config(struct pci_bus *bus,
			unsigned int devfn,
			int where,
			int size,
			u32 val)
{
	if (size == 1) {
		if (msp_pcibios_write_config_byte(bus, devfn,
						where, (u8)(0xFF & val))) {
			return -1;
		}
	} else if (size == 2) {
		if (msp_pcibios_write_config_word(bus, devfn,
						where, (u16)(0xFFFF & val))) {
			return -1;
		}
	} else if (size == 4) {
		if (msp_pcibios_write_config_dword(bus, devfn, where, val)) {
			return -1;
		}
	} else {
		return -1;
	}

	return PCIBIOS_SUCCESSFUL;
}