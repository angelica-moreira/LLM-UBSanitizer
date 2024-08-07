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
typedef  int u64 ;
typedef  int u32 ;
struct intel_iommu {int gcmd; int /*<<< orphan*/  register_lock; scalar_t__ reg; TYPE_1__* ir_table; } ;
struct TYPE_2__ {scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ DMAR_GCMD_REG ; 
 int /*<<< orphan*/  DMAR_GSTS_REG ; 
 scalar_t__ DMAR_IRTA_REG ; 
 int DMA_GCMD_SIRTP ; 
 int DMA_GSTS_IRTPS ; 
 int INTR_REMAP_TABLE_REG_SIZE ; 
 int /*<<< orphan*/  IOMMU_WAIT_OP (struct intel_iommu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int IR_X2APIC_MODE (int) ; 
 int /*<<< orphan*/  dmar_writeq (scalar_t__,int) ; 
 int /*<<< orphan*/  qi_global_iec (struct intel_iommu*) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  readl ; 
 int virt_to_phys (void*) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void iommu_set_irq_remapping(struct intel_iommu *iommu, int mode)
{
	unsigned long flags;
	u64 addr;
	u32 sts;

	addr = virt_to_phys((void *)iommu->ir_table->base);

	raw_spin_lock_irqsave(&iommu->register_lock, flags);

	dmar_writeq(iommu->reg + DMAR_IRTA_REG,
		    (addr) | IR_X2APIC_MODE(mode) | INTR_REMAP_TABLE_REG_SIZE);

	/* Set interrupt-remapping table pointer */
	writel(iommu->gcmd | DMA_GCMD_SIRTP, iommu->reg + DMAR_GCMD_REG);

	IOMMU_WAIT_OP(iommu, DMAR_GSTS_REG,
		      readl, (sts & DMA_GSTS_IRTPS), sts);
	raw_spin_unlock_irqrestore(&iommu->register_lock, flags);

	/*
	 * Global invalidation of interrupt entry cache to make sure the
	 * hardware uses the new irq remapping table.
	 */
	qi_global_iec(iommu);
}