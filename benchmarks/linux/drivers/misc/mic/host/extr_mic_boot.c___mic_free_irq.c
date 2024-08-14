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
struct vop_device {int /*<<< orphan*/  dev; } ;
struct mic_irq {int dummy; } ;
struct mic_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mic_free_irq (struct mic_device*,struct mic_irq*,void*) ; 
 struct mic_device* vpdev_to_mdev (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void __mic_free_irq(struct vop_device *vpdev,
			   struct mic_irq *cookie, void *data)
{
	struct mic_device *mdev = vpdev_to_mdev(&vpdev->dev);

	mic_free_irq(mdev, cookie, data);
}