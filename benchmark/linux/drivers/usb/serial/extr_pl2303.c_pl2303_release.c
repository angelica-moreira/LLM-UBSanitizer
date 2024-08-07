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
struct usb_serial {int dummy; } ;
struct pl2303_serial_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct pl2303_serial_private*) ; 
 struct pl2303_serial_private* usb_get_serial_data (struct usb_serial*) ; 

__attribute__((used)) static void pl2303_release(struct usb_serial *serial)
{
	struct pl2303_serial_private *spriv = usb_get_serial_data(serial);

	kfree(spriv);
}