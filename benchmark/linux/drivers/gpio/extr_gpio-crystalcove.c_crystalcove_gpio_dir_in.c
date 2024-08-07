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
 int /*<<< orphan*/  CTLO_INPUT_SET ; 
 int /*<<< orphan*/  CTRL_OUT ; 
 struct crystalcove_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int to_reg (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int crystalcove_gpio_dir_in(struct gpio_chip *chip, unsigned gpio)
{
	struct crystalcove_gpio *cg = gpiochip_get_data(chip);
	int reg = to_reg(gpio, CTRL_OUT);

	if (reg < 0)
		return 0;

	return regmap_write(cg->regmap, reg, CTLO_INPUT_SET);
}