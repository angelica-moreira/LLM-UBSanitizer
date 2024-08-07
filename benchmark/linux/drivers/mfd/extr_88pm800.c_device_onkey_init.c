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
struct pm80x_platform_data {int dummy; } ;
struct pm80x_chip {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 
 int mfd_add_devices (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * onkey_devs ; 
 int /*<<< orphan*/ * onkey_resources ; 

__attribute__((used)) static int device_onkey_init(struct pm80x_chip *chip,
				struct pm80x_platform_data *pdata)
{
	int ret;

	ret = mfd_add_devices(chip->dev, 0, &onkey_devs[0],
			      ARRAY_SIZE(onkey_devs), &onkey_resources[0], 0,
			      NULL);
	if (ret) {
		dev_err(chip->dev, "Failed to add onkey subdev\n");
		return ret;
	}

	return 0;
}