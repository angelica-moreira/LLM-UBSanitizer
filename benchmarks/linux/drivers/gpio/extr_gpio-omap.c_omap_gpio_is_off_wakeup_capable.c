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
struct gpio_bank {int non_wakeup_gpios; } ;

/* Variables and functions */

__attribute__((used)) static bool omap_gpio_is_off_wakeup_capable(struct gpio_bank *bank, u32 gpio_mask)
{
	u32 no_wake = bank->non_wakeup_gpios;

	if (no_wake)
		return !!(~no_wake & gpio_mask);

	return false;
}