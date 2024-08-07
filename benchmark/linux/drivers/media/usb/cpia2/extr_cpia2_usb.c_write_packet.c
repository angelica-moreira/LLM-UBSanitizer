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
typedef  int /*<<< orphan*/  u16 ;
struct usb_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HZ ; 
 int USB_RECIP_DEVICE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  kfree (unsigned char*) ; 
 unsigned char* kmemdup (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ) ; 
 int usb_control_msg (struct usb_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int write_packet(struct usb_device *udev,
			u8 request, u8 * registers, u16 start, size_t size)
{
	unsigned char *buf;
	int ret;

	if (!registers || size <= 0)
		return -EINVAL;

	buf = kmemdup(registers, size, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	ret = usb_control_msg(udev,
			       usb_sndctrlpipe(udev, 0),
			       request,
			       USB_TYPE_VENDOR | USB_RECIP_DEVICE,
			       start,	/* value */
			       0,	/* index */
			       buf,	/* buffer */
			       size,
			       HZ);

	kfree(buf);
	return ret;
}