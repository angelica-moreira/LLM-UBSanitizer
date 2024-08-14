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
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EPROBE_DEFER ; 
 int __platform_get_irq_byname (struct platform_device*,char const*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,char const*) ; 

int platform_get_irq_byname(struct platform_device *dev, const char *name)
{
	int ret;

	ret = __platform_get_irq_byname(dev, name);
	if (ret < 0 && ret != -EPROBE_DEFER)
		dev_err(&dev->dev, "IRQ %s not found\n", name);

	return ret;
}