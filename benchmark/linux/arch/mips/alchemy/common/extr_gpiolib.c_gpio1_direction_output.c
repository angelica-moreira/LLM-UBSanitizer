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
 unsigned int ALCHEMY_GPIO1_BASE ; 
 int alchemy_gpio1_direction_output (unsigned int,int) ; 

__attribute__((used)) static int gpio1_direction_output(struct gpio_chip *chip,
					unsigned offset, int value)
{
	return alchemy_gpio1_direction_output(offset + ALCHEMY_GPIO1_BASE,
					     value);
}