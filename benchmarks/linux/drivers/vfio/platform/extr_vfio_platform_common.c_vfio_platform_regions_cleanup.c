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
struct vfio_platform_device {int num_regions; TYPE_1__* regions; } ;
struct TYPE_2__ {int /*<<< orphan*/  ioaddr; } ;

/* Variables and functions */
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (TYPE_1__*) ; 

__attribute__((used)) static void vfio_platform_regions_cleanup(struct vfio_platform_device *vdev)
{
	int i;

	for (i = 0; i < vdev->num_regions; i++)
		iounmap(vdev->regions[i].ioaddr);

	vdev->num_regions = 0;
	kfree(vdev->regions);
}