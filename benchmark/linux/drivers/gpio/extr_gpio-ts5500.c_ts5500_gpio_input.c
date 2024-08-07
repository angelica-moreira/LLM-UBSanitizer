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
struct ts5500_dio {int /*<<< orphan*/  control_addr; int /*<<< orphan*/  control_mask; scalar_t__ no_output; scalar_t__ no_input; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int ENXIO ; 
 struct ts5500_priv* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  ts5500_clear_mask (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ts5500_gpio_input(struct gpio_chip *chip, unsigned offset)
{
	struct ts5500_priv *priv = gpiochip_get_data(chip);
	const struct ts5500_dio line = priv->pinout[offset];
	unsigned long flags;

	if (line.no_input)
		return -ENXIO;

	if (line.no_output)
		return 0;

	spin_lock_irqsave(&priv->lock, flags);
	ts5500_clear_mask(line.control_mask, line.control_addr);
	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}