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

/* Variables and functions */
 int /*<<< orphan*/  CORGI_GPIO_AC_IN ; 
 int /*<<< orphan*/  CORGI_GPIO_KEY_INT ; 
 int /*<<< orphan*/  CORGI_GPIO_WAKEUP ; 
 int /*<<< orphan*/  gpio_get_value (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool corgi_charger_wakeup(void)
{
	return !gpio_get_value(CORGI_GPIO_AC_IN) ||
		!gpio_get_value(CORGI_GPIO_KEY_INT) ||
		!gpio_get_value(CORGI_GPIO_WAKEUP);
}