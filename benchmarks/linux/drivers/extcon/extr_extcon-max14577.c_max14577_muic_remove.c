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
struct max14577_muic_info {int /*<<< orphan*/  irq_work; } ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_work_sync (int /*<<< orphan*/ *) ; 
 struct max14577_muic_info* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int max14577_muic_remove(struct platform_device *pdev)
{
	struct max14577_muic_info *info = platform_get_drvdata(pdev);

	cancel_work_sync(&info->irq_work);

	return 0;
}