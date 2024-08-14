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
struct i2c_tiny_usb {int /*<<< orphan*/  usb_dev; } ;
struct i2c_adapter {scalar_t__ algo_data; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int USB_DIR_IN ; 
 int USB_RECIP_INTERFACE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  kfree (void*) ; 
 void* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 int usb_control_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,int,void*,int,int) ; 
 int /*<<< orphan*/  usb_rcvctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int usb_read(struct i2c_adapter *adapter, int cmd,
		    int value, int index, void *data, int len)
{
	struct i2c_tiny_usb *dev = (struct i2c_tiny_usb *)adapter->algo_data;
	void *dmadata = kmalloc(len, GFP_KERNEL);
	int ret;

	if (!dmadata)
		return -ENOMEM;

	/* do control transfer */
	ret = usb_control_msg(dev->usb_dev, usb_rcvctrlpipe(dev->usb_dev, 0),
			       cmd, USB_TYPE_VENDOR | USB_RECIP_INTERFACE |
			       USB_DIR_IN, value, index, dmadata, len, 2000);

	memcpy(data, dmadata, len);
	kfree(dmadata);
	return ret;
}