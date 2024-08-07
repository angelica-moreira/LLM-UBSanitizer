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
struct irq_data {int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  GPIO_GFER ; 
 int /*<<< orphan*/  GPIO_GRER ; 
 unsigned int GPIO_IRQ_falling_edge ; 
 unsigned int GPIO_IRQ_mask ; 
 unsigned int GPIO_IRQ_rising_edge ; 
 unsigned int GPIO_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void puv3_high_gpio_unmask(struct irq_data *d)
{
	unsigned int mask = GPIO_MASK(d->irq);

	GPIO_IRQ_mask |= mask;

	writel(GPIO_IRQ_rising_edge & GPIO_IRQ_mask, GPIO_GRER);
	writel(GPIO_IRQ_falling_edge & GPIO_IRQ_mask, GPIO_GFER);
}