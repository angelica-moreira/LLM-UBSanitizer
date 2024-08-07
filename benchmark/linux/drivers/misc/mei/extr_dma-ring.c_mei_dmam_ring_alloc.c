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
struct mei_device {int /*<<< orphan*/ * dr_dscr; } ;

/* Variables and functions */
 int DMA_DSCR_NUM ; 
 int ENOMEM ; 
 scalar_t__ mei_dmam_dscr_alloc (struct mei_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mei_dmam_ring_free (struct mei_device*) ; 

int mei_dmam_ring_alloc(struct mei_device *dev)
{
	int i;

	for (i = 0; i < DMA_DSCR_NUM; i++)
		if (mei_dmam_dscr_alloc(dev, &dev->dr_dscr[i]))
			goto err;

	return 0;

err:
	mei_dmam_ring_free(dev);
	return -ENOMEM;
}