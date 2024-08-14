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
struct ccw_device {int /*<<< orphan*/  dev; } ;
typedef  int /*<<< orphan*/  async_cookie_t ;

/* Variables and functions */
 int ccw_device_set_online (struct ccw_device*) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_warn (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void dasd_generic_auto_online(void *data, async_cookie_t cookie)
{
	struct ccw_device *cdev = data;
	int ret;

	ret = ccw_device_set_online(cdev);
	if (ret)
		pr_warn("%s: Setting the DASD online failed with rc=%d\n",
			dev_name(&cdev->dev), ret);
}