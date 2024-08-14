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
struct gsta_gpio {int irq_base; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 struct gsta_gpio* gpiochip_get_data (struct gpio_chip*) ; 

__attribute__((used)) static int gsta_gpio_to_irq(struct gpio_chip *gpio, unsigned offset)
{
	struct gsta_gpio *chip = gpiochip_get_data(gpio);
	return chip->irq_base + offset;
}