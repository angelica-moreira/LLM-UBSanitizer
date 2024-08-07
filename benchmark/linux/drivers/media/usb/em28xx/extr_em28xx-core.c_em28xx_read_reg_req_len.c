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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct usb_device {int dummy; } ;
struct em28xx {int /*<<< orphan*/  ctrl_urb_lock; int /*<<< orphan*/  urb_buf; scalar_t__ disconnected; int /*<<< orphan*/  intf; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  HZ ; 
 int URB_MAX_CTRL_SIZE ; 
 int USB_DIR_IN ; 
 int USB_RECIP_DEVICE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  em28xx_regdbg (char*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int,int,...) ; 
 struct usb_device* interface_to_usbdev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int usb_control_msg (struct usb_device*,int,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int usb_rcvctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 
 int usb_translate_errors (int) ; 

int em28xx_read_reg_req_len(struct em28xx *dev, u8 req, u16 reg,
			    char *buf, int len)
{
	int ret;
	struct usb_device *udev = interface_to_usbdev(dev->intf);
	int pipe = usb_rcvctrlpipe(udev, 0);

	if (dev->disconnected)
		return -ENODEV;

	if (len > URB_MAX_CTRL_SIZE)
		return -EINVAL;

	mutex_lock(&dev->ctrl_urb_lock);
	ret = usb_control_msg(udev, pipe, req,
			      USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
			      0x0000, reg, dev->urb_buf, len, HZ);
	if (ret < 0) {
		em28xx_regdbg("(pipe 0x%08x): IN:  %02x %02x %02x %02x %02x %02x %02x %02x  failed with error %i\n",
			      pipe,
			      USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
			      req, 0, 0,
			      reg & 0xff, reg >> 8,
			      len & 0xff, len >> 8, ret);
		mutex_unlock(&dev->ctrl_urb_lock);
		return usb_translate_errors(ret);
	}

	if (len)
		memcpy(buf, dev->urb_buf, len);

	mutex_unlock(&dev->ctrl_urb_lock);

	em28xx_regdbg("(pipe 0x%08x): IN:  %02x %02x %02x %02x %02x %02x %02x %02x <<< %*ph\n",
		      pipe, USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
		      req, 0, 0,
		      reg & 0xff, reg >> 8,
		      len & 0xff, len >> 8, len, buf);

	return ret;
}