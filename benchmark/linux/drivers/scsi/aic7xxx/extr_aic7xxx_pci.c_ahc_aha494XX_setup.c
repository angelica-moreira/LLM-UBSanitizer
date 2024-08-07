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
struct ahc_softc {char channel; int /*<<< orphan*/  flags; int /*<<< orphan*/  dev_softc; } ;
typedef  int /*<<< orphan*/  ahc_dev_softc_t ;

/* Variables and functions */
#define  AHC_494X_SLOT_CHANNEL_A 131 
#define  AHC_494X_SLOT_CHANNEL_B 130 
#define  AHC_494X_SLOT_CHANNEL_C 129 
#define  AHC_494X_SLOT_CHANNEL_D 128 
 int /*<<< orphan*/  AHC_LARGE_SEEPROM ; 
 int ahc_get_pci_slot (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,int) ; 

__attribute__((used)) static int
ahc_aha494XX_setup(struct ahc_softc *ahc)
{
	ahc_dev_softc_t pci;

	pci = ahc->dev_softc;
	switch (ahc_get_pci_slot(pci)) {
	case AHC_494X_SLOT_CHANNEL_A:
		ahc->channel = 'A';
		break;
	case AHC_494X_SLOT_CHANNEL_B:
		ahc->channel = 'B';
		break;
	case AHC_494X_SLOT_CHANNEL_C:
		ahc->channel = 'C';
		break;
	case AHC_494X_SLOT_CHANNEL_D:
		ahc->channel = 'D';
		break;
	default:
		printk("adapter at unexpected slot %d\n"
		       "unable to map to a channel\n",
		       ahc_get_pci_slot(pci));
		ahc->channel = 'A';
	}
	ahc->flags |= AHC_LARGE_SEEPROM;
	return (0);
}