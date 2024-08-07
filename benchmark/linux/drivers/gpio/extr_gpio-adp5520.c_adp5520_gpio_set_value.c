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
struct adp5520_gpio {int /*<<< orphan*/ * lut; int /*<<< orphan*/  master; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADP5520_GPIO_OUT ; 
 int /*<<< orphan*/  adp5520_clr_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  adp5520_set_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct adp5520_gpio* gpiochip_get_data (struct gpio_chip*) ; 

__attribute__((used)) static void adp5520_gpio_set_value(struct gpio_chip *chip,
		unsigned off, int val)
{
	struct adp5520_gpio *dev;
	dev = gpiochip_get_data(chip);

	if (val)
		adp5520_set_bits(dev->master, ADP5520_GPIO_OUT, dev->lut[off]);
	else
		adp5520_clr_bits(dev->master, ADP5520_GPIO_OUT, dev->lut[off]);
}