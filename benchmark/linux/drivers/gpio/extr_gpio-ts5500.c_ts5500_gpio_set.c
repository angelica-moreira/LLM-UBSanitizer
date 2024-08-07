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
struct ts5500_priv {int /*<<< orphan*/  lock; struct ts5500_dio* pinout; } ;
struct ts5500_dio {int /*<<< orphan*/  value_addr; int /*<<< orphan*/  value_mask; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 struct ts5500_priv* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  ts5500_clear_mask (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ts5500_set_mask (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ts5500_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
	struct ts5500_priv *priv = gpiochip_get_data(chip);
	const struct ts5500_dio line = priv->pinout[offset];
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);
	if (val)
		ts5500_set_mask(line.value_mask, line.value_addr);
	else
		ts5500_clear_mask(line.value_mask, line.value_addr);
	spin_unlock_irqrestore(&priv->lock, flags);
}