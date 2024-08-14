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
typedef  int /*<<< orphan*/  u32 ;
typedef  scalar_t__ u16 ;
struct bcma_device {TYPE_1__* bus; } ;
struct TYPE_2__ {scalar_t__ mmio; struct bcma_device* mapped_core; } ;

/* Variables and functions */
 int BCMA_CORE_SIZE ; 
 int /*<<< orphan*/  bcma_host_pci_switch_core (struct bcma_device*) ; 
 int /*<<< orphan*/  ioread32 (scalar_t__) ; 

__attribute__((used)) static u32 bcma_host_pci_aread32(struct bcma_device *core, u16 offset)
{
	if (core->bus->mapped_core != core)
		bcma_host_pci_switch_core(core);
	return ioread32(core->bus->mmio + (1 * BCMA_CORE_SIZE) + offset);
}