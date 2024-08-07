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
struct solo_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SOLO_GPIO_DATA_OUT ; 
 unsigned int solo_reg_read (struct solo_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  solo_reg_write (struct solo_dev*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static void solo_gpio_set(struct solo_dev *solo_dev, unsigned int value)
{
	solo_reg_write(solo_dev, SOLO_GPIO_DATA_OUT,
		       solo_reg_read(solo_dev, SOLO_GPIO_DATA_OUT) | value);
}