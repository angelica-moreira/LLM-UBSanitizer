#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
struct pci_dev {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  dev; } ;
typedef  TYPE_1__ ide_hwif_t ;
struct TYPE_8__ {int dn; scalar_t__ dma_mode; scalar_t__ pio_mode; } ;
typedef  TYPE_2__ ide_drive_t ;

/* Variables and functions */
 scalar_t__ const XFER_MW_DMA_0 ; 
 scalar_t__ const XFER_PIO_0 ; 
 scalar_t__ const XFER_UDMA_0 ; 
 int /*<<< orphan*/  it8172_set_pio_mode (TYPE_1__*,TYPE_2__*) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,scalar_t__*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,scalar_t__) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void it8172_set_dma_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	struct pci_dev *dev	= to_pci_dev(hwif->dev);
	int a_speed		= 3 << (drive->dn * 4);
	int u_flag		= 1 << drive->dn;
	int u_speed		= 0;
	u8 reg48, reg4a;
	const u8 speed		= drive->dma_mode;

	pci_read_config_byte(dev, 0x48, &reg48);
	pci_read_config_byte(dev, 0x4a, &reg4a);

	if (speed >= XFER_UDMA_0) {
		u8 udma = speed - XFER_UDMA_0;
		u_speed = udma << (drive->dn * 4);

		pci_write_config_byte(dev, 0x48, reg48 | u_flag);
		reg4a &= ~a_speed;
		pci_write_config_byte(dev, 0x4a, reg4a | u_speed);
	} else {
		const u8 mwdma_to_pio[] = { 0, 3, 4 };

		pci_write_config_byte(dev, 0x48, reg48 & ~u_flag);
		pci_write_config_byte(dev, 0x4a, reg4a & ~a_speed);

		drive->pio_mode =
			mwdma_to_pio[speed - XFER_MW_DMA_0] + XFER_PIO_0;

		it8172_set_pio_mode(hwif, drive);
	}
}