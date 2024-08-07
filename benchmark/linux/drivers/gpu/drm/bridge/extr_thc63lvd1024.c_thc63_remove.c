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
struct thc63_dev {int /*<<< orphan*/  bridge; } ;
struct platform_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_bridge_remove (int /*<<< orphan*/ *) ; 
 struct thc63_dev* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int thc63_remove(struct platform_device *pdev)
{
	struct thc63_dev *thc63 = platform_get_drvdata(pdev);

	drm_bridge_remove(&thc63->bridge);

	return 0;
}