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
struct samsung_gpio_chip {scalar_t__ base; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 unsigned long __raw_readl (scalar_t__) ; 
 struct samsung_gpio_chip* to_samsung_gpio (struct gpio_chip*) ; 

__attribute__((used)) static int samsung_gpiolib_get(struct gpio_chip *chip, unsigned offset)
{
	struct samsung_gpio_chip *ourchip = to_samsung_gpio(chip);
	unsigned long val;

	val = __raw_readl(ourchip->base + 0x04);
	val >>= offset;
	val &= 1;

	return val;
}