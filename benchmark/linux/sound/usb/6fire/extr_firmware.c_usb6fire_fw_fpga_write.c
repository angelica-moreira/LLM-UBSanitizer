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
struct usb_device {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  FPGA_EP ; 
 int /*<<< orphan*/  HZ ; 
 int usb_bulk_msg (struct usb_device*,int /*<<< orphan*/ ,char*,int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndbulkpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int usb6fire_fw_fpga_write(struct usb_device *device,
		char *data, int len)
{
	int actual_len;
	int ret;

	ret = usb_bulk_msg(device, usb_sndbulkpipe(device, FPGA_EP), data, len,
			&actual_len, HZ);
	if (ret < 0)
		return ret;
	else if (actual_len != len)
		return -EIO;
	return 0;
}