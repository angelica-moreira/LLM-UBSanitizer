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
struct usb_device {int /*<<< orphan*/  dev; } ;
struct media_device {int dummy; } ;
struct dvb_usb_device {struct usb_device* udev; int /*<<< orphan*/  name; } ;
struct dvb_usb_adapter {int /*<<< orphan*/  dvb_adap; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct dvb_usb_device* adap_to_d (struct dvb_usb_adapter*) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dvb_register_media_controller (int /*<<< orphan*/ *,struct media_device*) ; 
 struct media_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  media_device_usb_init (struct media_device*,struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dvb_usbv2_media_device_init(struct dvb_usb_adapter *adap)
{
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
	struct media_device *mdev;
	struct dvb_usb_device *d = adap_to_d(adap);
	struct usb_device *udev = d->udev;

	mdev = kzalloc(sizeof(*mdev), GFP_KERNEL);
	if (!mdev)
		return -ENOMEM;

	media_device_usb_init(mdev, udev, d->name);

	dvb_register_media_controller(&adap->dvb_adap, mdev);

	dev_info(&d->udev->dev, "media controller created\n");
#endif
	return 0;
}