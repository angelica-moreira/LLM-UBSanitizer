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
struct radeonfb_info {int /*<<< orphan*/  bios_seg; } ;
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pci_unmap_rom (struct pci_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void radeon_unmap_ROM(struct radeonfb_info *rinfo, struct pci_dev *dev)
{
	if (!rinfo->bios_seg)
		return;
	pci_unmap_rom(dev, rinfo->bios_seg);
}