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
struct crystalcove_gpio {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  CTRL_OUT ; 
 struct crystalcove_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int,int,int) ; 
 int to_reg (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void crystalcove_gpio_set(struct gpio_chip *chip,
				 unsigned gpio, int value)
{
	struct crystalcove_gpio *cg = gpiochip_get_data(chip);
	int reg = to_reg(gpio, CTRL_OUT);

	if (reg < 0)
		return;

	if (value)
		regmap_update_bits(cg->regmap, reg, 1, 1);
	else
		regmap_update_bits(cg->regmap, reg, 1, 0);
}