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
struct pm860x_battery_info {int /*<<< orphan*/  dev; int /*<<< orphan*/  i2c; } ;

/* Variables and functions */
 int /*<<< orphan*/  PM8607_GPADC1_HIGHTH ; 
 int /*<<< orphan*/  PM8607_GPADC1_LOWTH ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  pm860x_reg_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void set_temp_threshold(struct pm860x_battery_info *info,
			       int min, int max)
{
	int data;

	/* (tmp << 8) / 1800 */
	if (min <= 0)
		data = 0;
	else
		data = (min << 8) / 1800;
	pm860x_reg_write(info->i2c, PM8607_GPADC1_HIGHTH, data);
	dev_dbg(info->dev, "TEMP_HIGHTH : min: %d, 0x%x\n", min, data);

	if (max <= 0)
		data = 0xff;
	else
		data = (max << 8) / 1800;
	pm860x_reg_write(info->i2c, PM8607_GPADC1_LOWTH, data);
	dev_dbg(info->dev, "TEMP_LOWTH:max : %d, 0x%x\n", max, data);
}