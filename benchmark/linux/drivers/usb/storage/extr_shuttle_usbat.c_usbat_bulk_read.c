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
struct us_data {int /*<<< orphan*/  recv_bulk_pipe; } ;

/* Variables and functions */
 int USB_STOR_XFER_GOOD ; 
 int usb_stor_bulk_transfer_sg (struct us_data*,int /*<<< orphan*/ ,void*,unsigned int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_stor_dbg (struct us_data*,char*,unsigned int) ; 

__attribute__((used)) static int usbat_bulk_read(struct us_data *us,
			   void* buf,
			   unsigned int len,
			   int use_sg)
{
	if (len == 0)
		return USB_STOR_XFER_GOOD;

	usb_stor_dbg(us, "len = %d\n", len);
	return usb_stor_bulk_transfer_sg(us, us->recv_bulk_pipe, buf, len, use_sg, NULL);
}