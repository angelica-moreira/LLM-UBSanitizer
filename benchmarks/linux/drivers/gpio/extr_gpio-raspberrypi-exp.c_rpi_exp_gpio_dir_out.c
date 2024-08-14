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
struct rpi_exp_gpio {int /*<<< orphan*/  fw; } ;
struct gpio_set_config {unsigned int gpio; int state; int polarity; scalar_t__ term_pull_up; scalar_t__ term_en; int /*<<< orphan*/  direction; } ;
struct gpio_chip {int /*<<< orphan*/  parent; } ;
typedef  int /*<<< orphan*/  set_out ;

/* Variables and functions */
 int EIO ; 
 int RPI_EXP_GPIO_BASE ; 
 int /*<<< orphan*/  RPI_EXP_GPIO_DIR_OUT ; 
 int /*<<< orphan*/  RPI_FIRMWARE_SET_GPIO_CONFIG ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,unsigned int,int,unsigned int) ; 
 struct rpi_exp_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int rpi_exp_gpio_get_polarity (struct gpio_chip*,unsigned int) ; 
 int rpi_firmware_property (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct gpio_set_config*,int) ; 

__attribute__((used)) static int rpi_exp_gpio_dir_out(struct gpio_chip *gc, unsigned int off, int val)
{
	struct rpi_exp_gpio *gpio;
	struct gpio_set_config set_out;
	int ret;

	gpio = gpiochip_get_data(gc);

	set_out.gpio = off + RPI_EXP_GPIO_BASE;	/* GPIO to update */
	set_out.direction = RPI_EXP_GPIO_DIR_OUT;
	set_out.term_en = 0;		/* n/a as an output */
	set_out.term_pull_up = 0;	/* n/a as termination disabled */
	set_out.state = val;		/* Output state */

	ret = rpi_exp_gpio_get_polarity(gc, off);
	if (ret < 0)
		return ret;
	set_out.polarity = ret;		/* Retain existing setting */

	ret = rpi_firmware_property(gpio->fw, RPI_FIRMWARE_SET_GPIO_CONFIG,
				    &set_out, sizeof(set_out));
	if (ret || set_out.gpio != 0) {
		dev_err(gc->parent, "Failed to set GPIO %u to output (%d %x)\n",
			off, ret, set_out.gpio);
		return ret ? ret : -EIO;
	}
	return 0;
}