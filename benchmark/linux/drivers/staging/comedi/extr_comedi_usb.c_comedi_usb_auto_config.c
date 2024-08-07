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
struct usb_interface {int /*<<< orphan*/  dev; } ;
struct comedi_driver {int dummy; } ;

/* Variables and functions */
 int comedi_auto_config (int /*<<< orphan*/ *,struct comedi_driver*,unsigned long) ; 

int comedi_usb_auto_config(struct usb_interface *intf,
			   struct comedi_driver *driver,
			   unsigned long context)
{
	return comedi_auto_config(&intf->dev, driver, context);
}