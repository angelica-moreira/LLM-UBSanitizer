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
struct adp5588_gpio {unsigned int* dir; unsigned int* dat_out; int /*<<< orphan*/  lock; int /*<<< orphan*/  client; } ;

/* Variables and functions */
 unsigned int ADP5588_BANK (unsigned int) ; 
 unsigned int ADP5588_BIT (unsigned int) ; 
 scalar_t__ GPIO_DAT_OUT1 ; 
 scalar_t__ GPIO_DIR1 ; 
 int adp5588_gpio_write (int /*<<< orphan*/ ,scalar_t__,unsigned int) ; 
 struct adp5588_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int adp5588_gpio_direction_output(struct gpio_chip *chip,
					 unsigned off, int val)
{
	int ret;
	unsigned bank, bit;
	struct adp5588_gpio *dev = gpiochip_get_data(chip);

	bank = ADP5588_BANK(off);
	bit = ADP5588_BIT(off);

	mutex_lock(&dev->lock);
	dev->dir[bank] |= bit;

	if (val)
		dev->dat_out[bank] |= bit;
	else
		dev->dat_out[bank] &= ~bit;

	ret = adp5588_gpio_write(dev->client, GPIO_DAT_OUT1 + bank,
				 dev->dat_out[bank]);
	ret |= adp5588_gpio_write(dev->client, GPIO_DIR1 + bank,
				 dev->dir[bank]);
	mutex_unlock(&dev->lock);

	return ret;
}