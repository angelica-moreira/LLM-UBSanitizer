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
struct kempld_gpio_data {struct kempld_device_data* pld; } ;
struct kempld_device_data {int dummy; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  KEMPLD_GPIO_LVL_NUM (unsigned int) ; 
 struct kempld_gpio_data* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  kempld_gpio_get_bit (struct kempld_device_data*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int kempld_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct kempld_gpio_data *gpio = gpiochip_get_data(chip);
	struct kempld_device_data *pld = gpio->pld;

	return !!kempld_gpio_get_bit(pld, KEMPLD_GPIO_LVL_NUM(offset), offset);
}