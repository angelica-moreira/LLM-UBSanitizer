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
struct hi655x_pmic {int /*<<< orphan*/  irq_data; int /*<<< orphan*/  gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpio_to_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mfd_remove_devices (int /*<<< orphan*/ *) ; 
 struct hi655x_pmic* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  regmap_del_irq_chip (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hi655x_pmic_remove(struct platform_device *pdev)
{
	struct hi655x_pmic *pmic = platform_get_drvdata(pdev);

	regmap_del_irq_chip(gpio_to_irq(pmic->gpio), pmic->irq_data);
	mfd_remove_devices(&pdev->dev);
	return 0;
}