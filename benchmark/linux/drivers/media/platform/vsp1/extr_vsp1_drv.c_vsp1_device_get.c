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
struct vsp1_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int pm_runtime_get_sync (int /*<<< orphan*/ ) ; 

int vsp1_device_get(struct vsp1_device *vsp1)
{
	int ret;

	ret = pm_runtime_get_sync(vsp1->dev);
	return ret < 0 ? ret : 0;
}