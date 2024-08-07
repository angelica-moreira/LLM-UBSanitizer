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
typedef  int /*<<< orphan*/  u8 ;
struct tc3589x {int /*<<< orphan*/  dev; int /*<<< orphan*/  i2c; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int) ; 
 int i2c_smbus_read_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int tc3589x_reg_read(struct tc3589x *tc3589x, u8 reg)
{
	int ret;

	ret = i2c_smbus_read_byte_data(tc3589x->i2c, reg);
	if (ret < 0)
		dev_err(tc3589x->dev, "failed to read reg %#x: %d\n",
			reg, ret);

	return ret;
}