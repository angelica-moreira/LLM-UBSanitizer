#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ power; } ;
struct backlight_device {TYPE_1__ props; } ;
struct acpi_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ FB_BLANK_POWERDOWN ; 
 struct acpi_device* bl_get_data (struct backlight_device*) ; 
 int get_lcd_level (struct acpi_device*) ; 

__attribute__((used)) static int bl_get_brightness(struct backlight_device *b)
{
	struct acpi_device *device = bl_get_data(b);

	return b->props.power == FB_BLANK_POWERDOWN ? 0 : get_lcd_level(device);
}