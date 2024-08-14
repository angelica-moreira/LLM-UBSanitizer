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
typedef  int u32 ;
struct gpio_chip {int dummy; } ;
struct bt8xxgpio {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT848_GPIO_DATA ; 
 int bgread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bgwrite (int,int /*<<< orphan*/ ) ; 
 struct bt8xxgpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void bt8xxgpio_gpio_set(struct gpio_chip *gpio,
			    unsigned nr, int val)
{
	struct bt8xxgpio *bg = gpiochip_get_data(gpio);
	unsigned long flags;
	u32 data;

	spin_lock_irqsave(&bg->lock, flags);

	data = bgread(BT848_GPIO_DATA);
	if (val)
		data |= (1 << nr);
	else
		data &= ~(1 << nr);
	bgwrite(data, BT848_GPIO_DATA);

	spin_unlock_irqrestore(&bg->lock, flags);
}