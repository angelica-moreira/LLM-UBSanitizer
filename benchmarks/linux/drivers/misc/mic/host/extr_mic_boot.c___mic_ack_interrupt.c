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
struct vop_device {int /*<<< orphan*/  dev; } ;
struct mic_device {TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* intr_workarounds ) (struct mic_device*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct mic_device*) ; 
 struct mic_device* vpdev_to_mdev (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void __mic_ack_interrupt(struct vop_device *vpdev, int num)
{
	struct mic_device *mdev = vpdev_to_mdev(&vpdev->dev);

	mdev->ops->intr_workarounds(mdev);
}