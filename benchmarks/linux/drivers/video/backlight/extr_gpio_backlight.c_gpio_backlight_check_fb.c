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
struct gpio_backlight {int /*<<< orphan*/ * fbdev; } ;
struct fb_info {int /*<<< orphan*/ * dev; } ;
struct backlight_device {int dummy; } ;

/* Variables and functions */
 struct gpio_backlight* bl_get_data (struct backlight_device*) ; 

__attribute__((used)) static int gpio_backlight_check_fb(struct backlight_device *bl,
				   struct fb_info *info)
{
	struct gpio_backlight *gbl = bl_get_data(bl);

	return gbl->fbdev == NULL || gbl->fbdev == info->dev;
}