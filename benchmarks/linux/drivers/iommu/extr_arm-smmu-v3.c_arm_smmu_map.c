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
struct iommu_domain {int dummy; } ;
struct io_pgtable_ops {int (* map ) (struct io_pgtable_ops*,unsigned long,int /*<<< orphan*/ ,size_t,int) ;} ;
typedef  int /*<<< orphan*/  phys_addr_t ;
struct TYPE_2__ {struct io_pgtable_ops* pgtbl_ops; } ;

/* Variables and functions */
 int ENODEV ; 
 int stub1 (struct io_pgtable_ops*,unsigned long,int /*<<< orphan*/ ,size_t,int) ; 
 TYPE_1__* to_smmu_domain (struct iommu_domain*) ; 

__attribute__((used)) static int arm_smmu_map(struct iommu_domain *domain, unsigned long iova,
			phys_addr_t paddr, size_t size, int prot)
{
	struct io_pgtable_ops *ops = to_smmu_domain(domain)->pgtbl_ops;

	if (!ops)
		return -ENODEV;

	return ops->map(ops, iova, paddr, size, prot);
}