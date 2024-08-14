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
struct isku_actual_profile {int size; int actual_profile; int /*<<< orphan*/  command; } ;

/* Variables and functions */
 int /*<<< orphan*/  ISKU_COMMAND_ACTUAL_PROFILE ; 
 int roccat_common2_send_with_status (struct usb_device*,int /*<<< orphan*/ ,struct isku_actual_profile*,int) ; 

__attribute__((used)) static int isku_set_actual_profile(struct usb_device *usb_dev, int new_profile)
{
	struct isku_actual_profile buf;

	buf.command = ISKU_COMMAND_ACTUAL_PROFILE;
	buf.size = sizeof(struct isku_actual_profile);
	buf.actual_profile = new_profile;
	return roccat_common2_send_with_status(usb_dev,
			ISKU_COMMAND_ACTUAL_PROFILE, &buf,
			sizeof(struct isku_actual_profile));
}