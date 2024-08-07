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
struct gpio_chip {int dummy; } ;
struct bd9571mwv_gpio {TYPE_1__* bd; } ;
struct TYPE_2__ {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  BD9571MWV_GPIO_OUT ; 
 int /*<<< orphan*/  BIT (unsigned int) ; 
 struct bd9571mwv_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bd9571mwv_gpio_set(struct gpio_chip *chip, unsigned int offset,
			      int value)
{
	struct bd9571mwv_gpio *gpio = gpiochip_get_data(chip);

	regmap_update_bits(gpio->bd->regmap, BD9571MWV_GPIO_OUT,
			   BIT(offset), value ? BIT(offset) : 0);
}