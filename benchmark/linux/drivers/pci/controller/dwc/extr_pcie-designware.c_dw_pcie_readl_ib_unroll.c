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
typedef  scalar_t__ u32 ;
struct dw_pcie {int dummy; } ;

/* Variables and functions */
 scalar_t__ PCIE_GET_ATU_INB_UNR_REG_OFFSET (scalar_t__) ; 
 scalar_t__ dw_pcie_readl_atu (struct dw_pcie*,scalar_t__) ; 

__attribute__((used)) static u32 dw_pcie_readl_ib_unroll(struct dw_pcie *pci, u32 index, u32 reg)
{
	u32 offset = PCIE_GET_ATU_INB_UNR_REG_OFFSET(index);

	return dw_pcie_readl_atu(pci, offset + reg);
}