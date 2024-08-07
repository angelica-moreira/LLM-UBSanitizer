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
typedef  int /*<<< orphan*/  u64 ;
struct device {int dummy; } ;

/* Variables and functions */
 int check_device (struct device*) ; 
 int /*<<< orphan*/  dma_direct_supported (struct device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int amd_iommu_dma_supported(struct device *dev, u64 mask)
{
	if (!dma_direct_supported(dev, mask))
		return 0;
	return check_device(dev);
}