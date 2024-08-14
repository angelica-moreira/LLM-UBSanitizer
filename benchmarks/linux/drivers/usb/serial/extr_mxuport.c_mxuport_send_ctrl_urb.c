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
struct usb_serial {int dummy; } ;

/* Variables and functions */
 int mxuport_send_ctrl_data_urb (struct usb_serial*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mxuport_send_ctrl_urb(struct usb_serial *serial,
				 u8 request, u16 value, u16 index)
{
	return mxuport_send_ctrl_data_urb(serial, request, value, index,
					  NULL, 0);
}