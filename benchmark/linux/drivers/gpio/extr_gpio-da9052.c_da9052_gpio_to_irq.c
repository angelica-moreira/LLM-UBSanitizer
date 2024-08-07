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
typedef  scalar_t__ u32 ;
struct gpio_chip {int dummy; } ;
struct da9052_gpio {struct da9052* da9052; } ;
struct da9052 {int /*<<< orphan*/  irq_data; } ;

/* Variables and functions */
 scalar_t__ DA9052_IRQ_GPI0 ; 
 struct da9052_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int regmap_irq_get_virq (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int da9052_gpio_to_irq(struct gpio_chip *gc, u32 offset)
{
	struct da9052_gpio *gpio = gpiochip_get_data(gc);
	struct da9052 *da9052 = gpio->da9052;

	int irq;

	irq = regmap_irq_get_virq(da9052->irq_data, DA9052_IRQ_GPI0 + offset);

	return irq;
}