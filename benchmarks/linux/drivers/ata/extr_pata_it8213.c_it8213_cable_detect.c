#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct pci_dev {int dummy; } ;
struct ata_port {TYPE_1__* host; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ATA_CBL_PATA40 ; 
 int ATA_CBL_PATA80 ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,int*) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int it8213_cable_detect(struct ata_port *ap)
{
	struct pci_dev *pdev = to_pci_dev(ap->host->dev);
	u8 tmp;
	pci_read_config_byte(pdev, 0x42, &tmp);
	if (tmp & 2)	/* The initial docs are incorrect */
		return ATA_CBL_PATA40;
	return ATA_CBL_PATA80;
}