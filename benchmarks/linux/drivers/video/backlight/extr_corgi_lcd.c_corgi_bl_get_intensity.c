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
struct corgi_lcd {int intensity; } ;
struct backlight_device {int dummy; } ;

/* Variables and functions */
 struct corgi_lcd* bl_get_data (struct backlight_device*) ; 

__attribute__((used)) static int corgi_bl_get_intensity(struct backlight_device *bd)
{
	struct corgi_lcd *lcd = bl_get_data(bd);

	return lcd->intensity;
}