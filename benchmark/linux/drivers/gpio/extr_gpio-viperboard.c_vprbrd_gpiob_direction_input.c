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
struct vprbrd_gpio {int gpiob_out; struct vprbrd* vb; } ;
struct vprbrd {int /*<<< orphan*/  lock; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 struct vprbrd_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int vprbrd_gpiob_setdir (struct vprbrd*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int vprbrd_gpiob_direction_input(struct gpio_chip *chip,
			unsigned int offset)
{
	int ret;
	struct vprbrd_gpio *gpio = gpiochip_get_data(chip);
	struct vprbrd *vb = gpio->vb;

	gpio->gpiob_out &= ~(1 << offset);

	mutex_lock(&vb->lock);

	ret = vprbrd_gpiob_setdir(vb, offset, 0);

	mutex_unlock(&vb->lock);

	if (ret)
		dev_err(chip->parent, "usb error setting pin to input\n");

	return ret;
}