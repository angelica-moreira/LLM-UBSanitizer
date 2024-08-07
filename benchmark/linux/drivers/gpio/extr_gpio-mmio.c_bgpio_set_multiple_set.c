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
struct gpio_chip {int /*<<< orphan*/  reg_set; } ;

/* Variables and functions */
 int /*<<< orphan*/  bgpio_set_multiple_single_reg (struct gpio_chip*,unsigned long*,unsigned long*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bgpio_set_multiple_set(struct gpio_chip *gc, unsigned long *mask,
				   unsigned long *bits)
{
	bgpio_set_multiple_single_reg(gc, mask, bits, gc->reg_set);
}