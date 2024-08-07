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
struct platform_device {scalar_t__ id; } ;
struct input_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  disable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  gpio_free (scalar_t__) ; 
 scalar_t__ input_get_drvdata (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 int /*<<< orphan*/  ixp4xx_spkr_control (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ixp4xx_timer2_irq ; 
 struct input_dev* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int ixp4xx_spkr_remove(struct platform_device *dev)
{
	struct input_dev *input_dev = platform_get_drvdata(dev);
	unsigned int pin = (unsigned int) input_get_drvdata(input_dev);

	input_unregister_device(input_dev);

	/* turn the speaker off */
	disable_irq(ixp4xx_timer2_irq);
	ixp4xx_spkr_control(pin, 0);

	free_irq(ixp4xx_timer2_irq, (void *)dev->id);
	gpio_free(dev->id);

	return 0;
}