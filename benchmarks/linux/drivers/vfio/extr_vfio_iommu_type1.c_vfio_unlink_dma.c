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
struct vfio_iommu {int /*<<< orphan*/  dma_list; } ;
struct vfio_dma {int /*<<< orphan*/  node; } ;

/* Variables and functions */
 int /*<<< orphan*/  rb_erase (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void vfio_unlink_dma(struct vfio_iommu *iommu, struct vfio_dma *old)
{
	rb_erase(&old->node, &iommu->dma_list);
}