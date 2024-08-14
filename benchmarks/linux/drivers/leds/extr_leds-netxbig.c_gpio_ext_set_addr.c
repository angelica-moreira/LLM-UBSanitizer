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
struct netxbig_gpio_ext {int num_addr; int /*<<< orphan*/ * addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void gpio_ext_set_addr(struct netxbig_gpio_ext *gpio_ext, int addr)
{
	int pin;

	for (pin = 0; pin < gpio_ext->num_addr; pin++)
		gpio_set_value(gpio_ext->addr[pin], (addr >> pin) & 1);
}