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
struct iommu_domain {int dummy; } ;
struct protection_domain {int flags; struct iommu_domain domain; } ;
struct pci_dev {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct protection_domain*) ; 
 int PD_IOMMUV2_MASK ; 
 struct protection_domain* get_domain (int /*<<< orphan*/ *) ; 

struct iommu_domain *amd_iommu_get_v2_domain(struct pci_dev *pdev)
{
	struct protection_domain *pdomain;

	pdomain = get_domain(&pdev->dev);
	if (IS_ERR(pdomain))
		return NULL;

	/* Only return IOMMUv2 domains */
	if (!(pdomain->flags & PD_IOMMUV2_MASK))
		return NULL;

	return &pdomain->domain;
}