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
struct hackrf_dev {int urbs_submitted; int /*<<< orphan*/ * urb_list; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  usb_kill_urb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hackrf_kill_urbs(struct hackrf_dev *dev)
{
	int i;

	for (i = dev->urbs_submitted - 1; i >= 0; i--) {
		dev_dbg(dev->dev, "kill urb=%d\n", i);
		/* stop the URB */
		usb_kill_urb(dev->urb_list[i]);
	}
	dev->urbs_submitted = 0;

	return 0;
}