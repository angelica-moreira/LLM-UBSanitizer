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
struct ahc_softc {char channel; int /*<<< orphan*/  dev_softc; } ;
typedef  int /*<<< orphan*/  ahc_dev_softc_t ;

/* Variables and functions */
#define  AHC_394X_SLOT_CHANNEL_A 129 
#define  AHC_394X_SLOT_CHANNEL_B 128 
 int ahc_get_pci_slot (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,int) ; 

__attribute__((used)) static int
ahc_aha394XX_setup(struct ahc_softc *ahc)
{
	ahc_dev_softc_t pci;

	pci = ahc->dev_softc;
	switch (ahc_get_pci_slot(pci)) {
	case AHC_394X_SLOT_CHANNEL_A:
		ahc->channel = 'A';
		break;
	case AHC_394X_SLOT_CHANNEL_B:
		ahc->channel = 'B';
		break;
	default:
		printk("adapter at unexpected slot %d\n"
		       "unable to map to a channel\n",
		       ahc_get_pci_slot(pci));
		ahc->channel = 'A';
	}
	return (0);
}