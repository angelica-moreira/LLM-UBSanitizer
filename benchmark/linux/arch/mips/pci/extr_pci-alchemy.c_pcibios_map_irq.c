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
struct pci_dev {struct alchemy_pci_context* sysdata; } ;
struct alchemy_pci_context {int (* board_map_irq ) (struct pci_dev const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (struct pci_dev const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	struct alchemy_pci_context *ctx = dev->sysdata;
	if (ctx && ctx->board_map_irq)
		return ctx->board_map_irq(dev, slot, pin);
	return -1;
}