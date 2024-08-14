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
struct usbnet {int interrupt_count; int /*<<< orphan*/  interrupt_mutex; TYPE_1__* udev; int /*<<< orphan*/ * interrupt; } ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON_ONCE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int usb_submit_urb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int usbnet_status_start(struct usbnet *dev, gfp_t mem_flags)
{
	int ret = 0;

	WARN_ON_ONCE(dev->interrupt == NULL);
	if (dev->interrupt) {
		mutex_lock(&dev->interrupt_mutex);

		if (++dev->interrupt_count == 1)
			ret = usb_submit_urb(dev->interrupt, mem_flags);

		dev_dbg(&dev->udev->dev, "incremented interrupt URB count to %d\n",
			dev->interrupt_count);
		mutex_unlock(&dev->interrupt_mutex);
	}
	return ret;
}