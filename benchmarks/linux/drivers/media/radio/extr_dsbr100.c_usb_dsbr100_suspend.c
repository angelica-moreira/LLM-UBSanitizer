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
struct usb_interface {int /*<<< orphan*/  dev; } ;
struct dsbr100_device {int /*<<< orphan*/  v4l2_lock; int /*<<< orphan*/  muted; } ;
typedef  int /*<<< orphan*/  pm_message_t ;

/* Variables and functions */
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ dsbr100_stop (struct dsbr100_device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct dsbr100_device* usb_get_intfdata (struct usb_interface*) ; 

__attribute__((used)) static int usb_dsbr100_suspend(struct usb_interface *intf, pm_message_t message)
{
	struct dsbr100_device *radio = usb_get_intfdata(intf);

	mutex_lock(&radio->v4l2_lock);
	if (!radio->muted && dsbr100_stop(radio) < 0)
		dev_warn(&intf->dev, "dsbr100_stop failed\n");
	mutex_unlock(&radio->v4l2_lock);

	dev_info(&intf->dev, "going into suspend..\n");
	return 0;
}