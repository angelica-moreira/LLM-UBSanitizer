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
 int /*<<< orphan*/  em_gio_direction_input (struct gpio_chip*,unsigned int) ; 
 int /*<<< orphan*/  pinctrl_gpio_free (unsigned int) ; 

__attribute__((used)) static void em_gio_free(struct gpio_chip *chip, unsigned offset)
{
	pinctrl_gpio_free(chip->base + offset);

	/* Set the GPIO as an input to ensure that the next GPIO request won't
	* drive the GPIO pin as an output.
	*/
	em_gio_direction_input(chip, offset);
}