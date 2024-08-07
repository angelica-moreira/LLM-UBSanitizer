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
struct scif_hw_dev {int dummy; } ;
struct mic_device {int dummy; } ;
struct device {int dummy; } ;
typedef  int gfp_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int __GFP_ZERO ; 
 struct scif_hw_dev* dev_get_drvdata (struct device*) ; 
 scalar_t__ dma_mapping_error (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (void*) ; 
 void* kmalloc (size_t,int) ; 
 int /*<<< orphan*/  mic_map_single (struct mic_device*,void*,size_t) ; 
 struct mic_device* scdev_to_mdev (struct scif_hw_dev*) ; 

__attribute__((used)) static void *__mic_dma_alloc(struct device *dev, size_t size,
			     dma_addr_t *dma_handle, gfp_t gfp,
			     unsigned long attrs)
{
	struct scif_hw_dev *scdev = dev_get_drvdata(dev);
	struct mic_device *mdev = scdev_to_mdev(scdev);
	dma_addr_t tmp;
	void *va = kmalloc(size, gfp | __GFP_ZERO);

	if (va) {
		tmp = mic_map_single(mdev, va, size);
		if (dma_mapping_error(dev, tmp)) {
			kfree(va);
			va = NULL;
		} else {
			*dma_handle = tmp;
		}
	}
	return va;
}