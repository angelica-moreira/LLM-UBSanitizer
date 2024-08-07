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
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpiochip_get_data (struct gpio_chip*) ; 
 int meson_pinconf_set_output (int /*<<< orphan*/ ,unsigned int,int) ; 

__attribute__((used)) static int meson_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
	return meson_pinconf_set_output(gpiochip_get_data(chip), gpio, false);
}