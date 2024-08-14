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
struct oxnas_pinctrl {struct oxnas_gpio_bank* gpio_banks; } ;
struct oxnas_gpio_bank {int dummy; } ;

/* Variables and functions */
 unsigned int PINS_PER_BANK ; 

__attribute__((used)) static inline struct oxnas_gpio_bank *pctl_to_bank(struct oxnas_pinctrl *pctl,
						   unsigned int pin)
{
	return &pctl->gpio_banks[pin / PINS_PER_BANK];
}