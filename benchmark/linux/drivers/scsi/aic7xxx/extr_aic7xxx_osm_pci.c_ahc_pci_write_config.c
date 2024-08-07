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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  ahc_dev_softc_t ;

/* Variables and functions */
 int /*<<< orphan*/  panic (char*) ; 
 int /*<<< orphan*/  pci_write_config_byte (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_write_config_dword (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_write_config_word (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

void
ahc_pci_write_config(ahc_dev_softc_t pci, int reg, uint32_t value, int width)
{
	switch (width) {
	case 1:
		pci_write_config_byte(pci, reg, value);
		break;
	case 2:
		pci_write_config_word(pci, reg, value);
		break;
	case 4:
		pci_write_config_dword(pci, reg, value);
		break;
	default:
		panic("ahc_pci_write_config: Write size too big");
		/* NOTREACHED */
	}
}