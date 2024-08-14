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
struct dc_link {int connector_signal; scalar_t__ type; } ;
struct amdgpu_display_manager {struct dc_link* backlight_link; scalar_t__ backlight_dev; } ;

/* Variables and functions */
 int SIGNAL_TYPE_EDP ; 
 int SIGNAL_TYPE_LVDS ; 
 int /*<<< orphan*/  amdgpu_dm_register_backlight_device (struct amdgpu_display_manager*) ; 
 scalar_t__ dc_connection_none ; 

__attribute__((used)) static void register_backlight_device(struct amdgpu_display_manager *dm,
				      struct dc_link *link)
{
#if defined(CONFIG_BACKLIGHT_CLASS_DEVICE) ||\
	defined(CONFIG_BACKLIGHT_CLASS_DEVICE_MODULE)

	if ((link->connector_signal & (SIGNAL_TYPE_EDP | SIGNAL_TYPE_LVDS)) &&
	    link->type != dc_connection_none) {
		/*
		 * Event if registration failed, we should continue with
		 * DM initialization because not having a backlight control
		 * is better then a black screen.
		 */
		amdgpu_dm_register_backlight_device(dm);

		if (dm->backlight_dev)
			dm->backlight_link = link;
	}
#endif
}