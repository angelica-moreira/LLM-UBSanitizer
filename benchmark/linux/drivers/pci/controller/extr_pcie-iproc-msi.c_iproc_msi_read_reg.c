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
typedef  int /*<<< orphan*/  u32 ;
struct iproc_pcie {scalar_t__ base; } ;
struct iproc_msi {scalar_t__** reg_offsets; struct iproc_pcie* pcie; } ;
typedef  enum iproc_msi_reg { ____Placeholder_iproc_msi_reg } iproc_msi_reg ;

/* Variables and functions */
 int /*<<< orphan*/  readl_relaxed (scalar_t__) ; 

__attribute__((used)) static inline u32 iproc_msi_read_reg(struct iproc_msi *msi,
				     enum iproc_msi_reg reg,
				     unsigned int eq)
{
	struct iproc_pcie *pcie = msi->pcie;

	return readl_relaxed(pcie->base + msi->reg_offsets[eq][reg]);
}