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
struct rza1_port {int dummy; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 struct rza1_port* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  rza1_pin_set_direction (struct rza1_port*,unsigned int,int) ; 

__attribute__((used)) static int rza1_gpio_direction_input(struct gpio_chip *chip,
				     unsigned int gpio)
{
	struct rza1_port *port = gpiochip_get_data(chip);

	rza1_pin_set_direction(port, gpio, true);

	return 0;
}