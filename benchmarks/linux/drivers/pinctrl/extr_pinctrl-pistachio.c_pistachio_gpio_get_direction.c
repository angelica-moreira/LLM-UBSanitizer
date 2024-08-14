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
struct pistachio_gpio_bank {int dummy; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int /*<<< orphan*/  GPIO_OUTPUT_EN ; 
 int gpio_readl (struct pistachio_gpio_bank*,int /*<<< orphan*/ ) ; 
 struct pistachio_gpio_bank* gpiochip_get_data (struct gpio_chip*) ; 

__attribute__((used)) static int pistachio_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
	struct pistachio_gpio_bank *bank = gpiochip_get_data(chip);

	return !(gpio_readl(bank, GPIO_OUTPUT_EN) & BIT(offset));
}