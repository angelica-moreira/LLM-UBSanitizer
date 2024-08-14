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
struct usbnet {int dummy; } ;

/* Variables and functions */
 int USB_DIR_IN ; 
 int USB_RECIP_DEVICE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  le16_to_cpus (int /*<<< orphan*/ *) ; 
 int usbnet_read_cmd (struct usbnet*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
nc_vendor_read(struct usbnet *dev, u8 req, u8 regnum, u16 *retval_ptr)
{
	int status = usbnet_read_cmd(dev, req,
				     USB_DIR_IN | USB_TYPE_VENDOR |
				     USB_RECIP_DEVICE,
				     0, regnum, retval_ptr,
				     sizeof *retval_ptr);
	if (status > 0)
		status = 0;
	if (!status)
		le16_to_cpus(retval_ptr);
	return status;
}