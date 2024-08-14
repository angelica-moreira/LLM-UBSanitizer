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
struct TYPE_2__ {int mul; int div; int /*<<< orphan*/  max_usec; } ;
struct vnic_dev {TYPE_1__ intr_coal_timer_info; } ;

/* Variables and functions */
 int /*<<< orphan*/  vnic_dev_intr_coal_timer_hw_to_usec (struct vnic_dev*,int) ; 

void vnic_dev_intr_coal_timer_info_default(struct vnic_dev *vdev)
{
	/* Default: hardware intr coal timer is in units of 1.5 usecs */
	vdev->intr_coal_timer_info.mul = 2;
	vdev->intr_coal_timer_info.div = 3;
	vdev->intr_coal_timer_info.max_usec =
		vnic_dev_intr_coal_timer_hw_to_usec(vdev, 0xffff);
}