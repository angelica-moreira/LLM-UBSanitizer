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
struct usb_role_switch {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR_OR_NULL (struct usb_role_switch*) ; 
 int /*<<< orphan*/  device_unregister (int /*<<< orphan*/ *) ; 

void usb_role_switch_unregister(struct usb_role_switch *sw)
{
	if (!IS_ERR_OR_NULL(sw))
		device_unregister(&sw->dev);
}