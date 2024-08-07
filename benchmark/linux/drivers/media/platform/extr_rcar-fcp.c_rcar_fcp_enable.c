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
struct rcar_fcp_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int pm_runtime_get_sync (int /*<<< orphan*/ ) ; 

int rcar_fcp_enable(struct rcar_fcp_device *fcp)
{
	int ret;

	if (!fcp)
		return 0;

	ret = pm_runtime_get_sync(fcp->dev);
	if (ret < 0)
		return ret;

	return 0;
}