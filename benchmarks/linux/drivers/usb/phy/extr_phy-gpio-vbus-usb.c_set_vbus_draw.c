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
struct regulator {int dummy; } ;
struct gpio_vbus_data {int vbus_draw_enabled; unsigned int mA; struct regulator* vbus_draw; } ;

/* Variables and functions */
 int regulator_disable (struct regulator*) ; 
 int regulator_enable (struct regulator*) ; 
 int /*<<< orphan*/  regulator_set_current_limit (struct regulator*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void set_vbus_draw(struct gpio_vbus_data *gpio_vbus, unsigned mA)
{
	struct regulator *vbus_draw = gpio_vbus->vbus_draw;
	int enabled;
	int ret;

	if (!vbus_draw)
		return;

	enabled = gpio_vbus->vbus_draw_enabled;
	if (mA) {
		regulator_set_current_limit(vbus_draw, 0, 1000 * mA);
		if (!enabled) {
			ret = regulator_enable(vbus_draw);
			if (ret < 0)
				return;
			gpio_vbus->vbus_draw_enabled = 1;
		}
	} else {
		if (enabled) {
			ret = regulator_disable(vbus_draw);
			if (ret < 0)
				return;
			gpio_vbus->vbus_draw_enabled = 0;
		}
	}
	gpio_vbus->mA = mA;
}