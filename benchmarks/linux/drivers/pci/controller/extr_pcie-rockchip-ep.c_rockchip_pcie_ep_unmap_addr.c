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
struct rockchip_pcie {int dummy; } ;
struct rockchip_pcie_ep {int max_regions; scalar_t__* ob_addr; int /*<<< orphan*/  ob_region_map; struct rockchip_pcie rockchip; } ;
struct pci_epc {int dummy; } ;
typedef  scalar_t__ phys_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  clear_bit (int,int /*<<< orphan*/ *) ; 
 struct rockchip_pcie_ep* epc_get_drvdata (struct pci_epc*) ; 
 int /*<<< orphan*/  rockchip_pcie_clear_ep_ob_atu (struct rockchip_pcie*,int) ; 

__attribute__((used)) static void rockchip_pcie_ep_unmap_addr(struct pci_epc *epc, u8 fn,
					phys_addr_t addr)
{
	struct rockchip_pcie_ep *ep = epc_get_drvdata(epc);
	struct rockchip_pcie *rockchip = &ep->rockchip;
	u32 r;

	for (r = 0; r < ep->max_regions - 1; r++)
		if (ep->ob_addr[r] == addr)
			break;

	/*
	 * Region 0 is reserved for configuration space and shouldn't
	 * be used elsewhere per TRM, so leave it out.
	 */
	if (r == ep->max_regions - 1)
		return;

	rockchip_pcie_clear_ep_ob_atu(rockchip, r);

	ep->ob_addr[r] = 0;
	clear_bit(r, &ep->ob_region_map);
}