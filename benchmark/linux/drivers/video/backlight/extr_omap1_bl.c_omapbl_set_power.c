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
struct omap_backlight {int powermode; } ;
struct backlight_device {int dummy; } ;

/* Variables and functions */
 struct omap_backlight* bl_get_data (struct backlight_device*) ; 
 int /*<<< orphan*/  omapbl_blank (struct omap_backlight*,int) ; 

__attribute__((used)) static int omapbl_set_power(struct backlight_device *dev, int state)
{
	struct omap_backlight *bl = bl_get_data(dev);

	omapbl_blank(bl, state);
	bl->powermode = state;

	return 0;
}