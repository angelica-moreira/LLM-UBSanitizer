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
struct irqc_priv {int /*<<< orphan*/  irq_domain; } ;

/* Variables and functions */
 int /*<<< orphan*/  irq_domain_remove (int /*<<< orphan*/ ) ; 
 struct irqc_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int irqc_remove(struct platform_device *pdev)
{
	struct irqc_priv *p = platform_get_drvdata(pdev);

	irq_domain_remove(p->irq_domain);
	pm_runtime_put(&pdev->dev);
	pm_runtime_disable(&pdev->dev);
	return 0;
}