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
struct ts4900_gpio_priv {int /*<<< orphan*/  regmap; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int TS4900_GPIO_OE ; 
 int TS4900_GPIO_OUT ; 
 struct ts4900_gpio_priv* gpiochip_get_data (struct gpio_chip*) ; 
 int regmap_write (int /*<<< orphan*/ ,unsigned int,int) ; 

__attribute__((used)) static int ts4900_gpio_direction_output(struct gpio_chip *chip,
					unsigned int offset, int value)
{
	struct ts4900_gpio_priv *priv = gpiochip_get_data(chip);
	int ret;

	if (value)
		ret = regmap_write(priv->regmap, offset, TS4900_GPIO_OE |
							 TS4900_GPIO_OUT);
	else
		ret = regmap_write(priv->regmap, offset, TS4900_GPIO_OE);

	return ret;
}