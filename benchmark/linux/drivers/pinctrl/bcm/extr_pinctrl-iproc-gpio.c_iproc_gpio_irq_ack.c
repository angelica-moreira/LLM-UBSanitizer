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
typedef  int /*<<< orphan*/  u32 ;
struct irq_data {unsigned int hwirq; } ;
struct iproc_gpio {scalar_t__ base; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (unsigned int) ; 
 int /*<<< orphan*/  IPROC_GPIO_INT_CLR_OFFSET ; 
 unsigned int IPROC_GPIO_REG (unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int IPROC_GPIO_SHIFT (unsigned int) ; 
 struct iproc_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 struct gpio_chip* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void iproc_gpio_irq_ack(struct irq_data *d)
{
	struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
	struct iproc_gpio *chip = gpiochip_get_data(gc);
	unsigned gpio = d->hwirq;
	unsigned int offset = IPROC_GPIO_REG(gpio,
			IPROC_GPIO_INT_CLR_OFFSET);
	unsigned int shift = IPROC_GPIO_SHIFT(gpio);
	u32 val = BIT(shift);

	writel(val, chip->base + offset);
}