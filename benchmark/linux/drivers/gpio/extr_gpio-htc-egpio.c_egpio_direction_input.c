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
struct gpio_chip {int dummy; } ;
struct egpio_chip {int /*<<< orphan*/  is_out; } ;

/* Variables and functions */
 int EINVAL ; 
 struct egpio_chip* gpiochip_get_data (struct gpio_chip*) ; 
 scalar_t__ test_bit (unsigned int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int egpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
	struct egpio_chip *egpio;

	egpio = gpiochip_get_data(chip);
	return test_bit(offset, &egpio->is_out) ? -EINVAL : 0;
}