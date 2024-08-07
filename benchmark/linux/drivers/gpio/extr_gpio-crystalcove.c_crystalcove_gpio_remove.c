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
struct platform_device {int dummy; } ;
struct crystalcove_gpio {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  free_irq (int,struct crystalcove_gpio*) ; 
 struct crystalcove_gpio* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int crystalcove_gpio_remove(struct platform_device *pdev)
{
	struct crystalcove_gpio *cg = platform_get_drvdata(pdev);
	int irq = platform_get_irq(pdev, 0);

	if (irq >= 0)
		free_irq(irq, cg);
	return 0;
}