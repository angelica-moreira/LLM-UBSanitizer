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
struct amd_iommu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONTROL_IOMMU_EN ; 
 int /*<<< orphan*/  iommu_feature_enable (struct amd_iommu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void iommu_enable(struct amd_iommu *iommu)
{
	iommu_feature_enable(iommu, CONTROL_IOMMU_EN);
}