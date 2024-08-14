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
typedef  int /*<<< orphan*/  u16 ;
struct usb_device {int dummy; } ;
struct gspca_dev {int usb_err; struct usb_device* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  PAC207_CTRL_TIMEOUT ; 
 int USB_DIR_OUT ; 
 int USB_RECIP_INTERFACE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int usb_control_msg (struct usb_device*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pac207_write_reg(struct gspca_dev *gspca_dev, u16 index, u16 value)
{
	struct usb_device *udev = gspca_dev->dev;
	int err;

	if (gspca_dev->usb_err < 0)
		return;

	err = usb_control_msg(udev, usb_sndctrlpipe(udev, 0), 0x00,
			USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_INTERFACE,
			value, index, NULL, 0, PAC207_CTRL_TIMEOUT);
	if (err) {
		pr_err("Failed to write a register (index 0x%04X, value 0x%02X, error %d)\n",
		       index, value, err);
		gspca_dev->usb_err = err;
	}
}