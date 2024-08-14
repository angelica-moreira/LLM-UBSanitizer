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
struct lpc32xx_gpio_chip {int dummy; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __get_gpi_state_p3 (struct lpc32xx_gpio_chip*,unsigned int) ; 
 struct lpc32xx_gpio_chip* gpiochip_get_data (struct gpio_chip*) ; 

__attribute__((used)) static int lpc32xx_gpi_get_value(struct gpio_chip *chip, unsigned pin)
{
	struct lpc32xx_gpio_chip *group = gpiochip_get_data(chip);

	return !!__get_gpi_state_p3(group, pin);
}