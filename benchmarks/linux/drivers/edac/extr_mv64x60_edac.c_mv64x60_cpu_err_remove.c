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
struct edac_device_ctl_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  edac_dbg (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  edac_device_del_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  edac_device_free_ctl_info (struct edac_device_ctl_info*) ; 
 struct edac_device_ctl_info* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int mv64x60_cpu_err_remove(struct platform_device *pdev)
{
	struct edac_device_ctl_info *edac_dev = platform_get_drvdata(pdev);

	edac_dbg(0, "\n");

	edac_device_del_device(&pdev->dev);
	edac_device_free_ctl_info(edac_dev);
	return 0;
}