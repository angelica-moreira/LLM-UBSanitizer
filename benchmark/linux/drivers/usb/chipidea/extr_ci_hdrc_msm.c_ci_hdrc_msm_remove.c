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
struct ci_hdrc_msm {int /*<<< orphan*/  core_clk; int /*<<< orphan*/  iface_clk; int /*<<< orphan*/  ci; } ;

/* Variables and functions */
 int /*<<< orphan*/  ci_hdrc_remove_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 struct ci_hdrc_msm* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ci_hdrc_msm_remove(struct platform_device *pdev)
{
	struct ci_hdrc_msm *ci = platform_get_drvdata(pdev);

	pm_runtime_disable(&pdev->dev);
	ci_hdrc_remove_device(ci->ci);
	clk_disable_unprepare(ci->iface_clk);
	clk_disable_unprepare(ci->core_clk);

	return 0;
}