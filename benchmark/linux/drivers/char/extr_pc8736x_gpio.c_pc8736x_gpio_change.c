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
 int /*<<< orphan*/  pc8736x_gpio_current (unsigned int) ; 
 int /*<<< orphan*/  pc8736x_gpio_set (unsigned int,int) ; 

__attribute__((used)) static void pc8736x_gpio_change(unsigned index)
{
	pc8736x_gpio_set(index, !pc8736x_gpio_current(index));
}