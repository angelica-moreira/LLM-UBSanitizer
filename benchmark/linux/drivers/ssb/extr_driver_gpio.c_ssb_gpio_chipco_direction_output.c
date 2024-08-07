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
struct ssb_bus {int /*<<< orphan*/  chipco; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 struct ssb_bus* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  ssb_chipco_gpio_out (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  ssb_chipco_gpio_outen (int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int ssb_gpio_chipco_direction_output(struct gpio_chip *chip,
					    unsigned int gpio, int value)
{
	struct ssb_bus *bus = gpiochip_get_data(chip);

	ssb_chipco_gpio_outen(&bus->chipco, 1 << gpio, 1 << gpio);
	ssb_chipco_gpio_out(&bus->chipco, 1 << gpio, value ? 1 << gpio : 0);
	return 0;
}