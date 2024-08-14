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
typedef  int u8 ;
struct dvb_usb_adapter {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int DIBUSB_IOCTL_CMD_DISABLE_STREAM ; 
 int DIBUSB_IOCTL_CMD_ENABLE_STREAM ; 
 int DIBUSB_REQ_SET_IOCTL ; 
 int DIBUSB_REQ_SET_STREAMING_MODE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int dibusb_streaming_ctrl (struct dvb_usb_adapter*,int) ; 
 int dvb_usb_generic_write (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 

int dibusb2_0_streaming_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
	int ret;
	u8 *b;

	b = kmalloc(3, GFP_KERNEL);
	if (!b)
		return -ENOMEM;

	if ((ret = dibusb_streaming_ctrl(adap,onoff)) < 0)
		goto ret;

	if (onoff) {
		b[0] = DIBUSB_REQ_SET_STREAMING_MODE;
		b[1] = 0x00;
		ret = dvb_usb_generic_write(adap->dev, b, 2);
		if (ret  < 0)
			goto ret;
	}

	b[0] = DIBUSB_REQ_SET_IOCTL;
	b[1] = onoff ? DIBUSB_IOCTL_CMD_ENABLE_STREAM : DIBUSB_IOCTL_CMD_DISABLE_STREAM;
	ret = dvb_usb_generic_write(adap->dev, b, 3);

ret:
	kfree(b);
	return ret;
}