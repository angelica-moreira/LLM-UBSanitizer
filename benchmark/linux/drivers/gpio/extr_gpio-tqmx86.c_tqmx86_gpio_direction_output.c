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

/* Variables and functions */
 int BIT (unsigned int) ; 
 int EINVAL ; 
 int TQMX86_DIR_INPUT_MASK ; 
 int /*<<< orphan*/  tqmx86_gpio_set (struct gpio_chip*,unsigned int,int) ; 

__attribute__((used)) static int tqmx86_gpio_direction_output(struct gpio_chip *chip,
					unsigned int offset,
					int value)
{
	/* Direction cannot be changed, validate is an output */
	if (BIT(offset) & TQMX86_DIR_INPUT_MASK)
		return -EINVAL;

	tqmx86_gpio_set(chip, offset, value);
	return 0;
}