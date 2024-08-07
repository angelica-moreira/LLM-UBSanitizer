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
struct ahc_softc {char channel; int instruction_ram_size; int /*<<< orphan*/  bugs; int /*<<< orphan*/  flags; int /*<<< orphan*/  features; int /*<<< orphan*/  chip; int /*<<< orphan*/  dev_softc; } ;
typedef  int /*<<< orphan*/  ahc_dev_softc_t ;

/* Variables and functions */
 int /*<<< orphan*/  AHC_AIC7899 ; 
 int /*<<< orphan*/  AHC_AIC7899_FE ; 
 int /*<<< orphan*/  AHC_NEWEEPROM_FMT ; 
 int /*<<< orphan*/  AHC_SCBCHAN_UPLOAD_BUG ; 
 int ahc_get_pci_function (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ahc_aic7899_setup(struct ahc_softc *ahc)
{
	ahc_dev_softc_t pci;

	pci = ahc->dev_softc;
	ahc->channel = ahc_get_pci_function(pci) == 1 ? 'B' : 'A';
	ahc->chip = AHC_AIC7899;
	ahc->features = AHC_AIC7899_FE;
	ahc->flags |= AHC_NEWEEPROM_FMT;
	ahc->bugs |= AHC_SCBCHAN_UPLOAD_BUG;
	ahc->instruction_ram_size = 1024;
	return (0);
}