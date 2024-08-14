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
struct gpio_chip {unsigned int base; } ;

/* Variables and functions */
 int pinctrl_gpio_direction_input (unsigned int) ; 

__attribute__((used)) static int rockchip_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
	return pinctrl_gpio_direction_input(gc->base + offset);
}