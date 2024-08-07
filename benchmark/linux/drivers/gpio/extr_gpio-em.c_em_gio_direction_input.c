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
 int /*<<< orphan*/  BIT (unsigned int) ; 
 int /*<<< orphan*/  GIO_E0 ; 
 int /*<<< orphan*/  em_gio_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_to_priv (struct gpio_chip*) ; 

__attribute__((used)) static int em_gio_direction_input(struct gpio_chip *chip, unsigned offset)
{
	em_gio_write(gpio_to_priv(chip), GIO_E0, BIT(offset));
	return 0;
}