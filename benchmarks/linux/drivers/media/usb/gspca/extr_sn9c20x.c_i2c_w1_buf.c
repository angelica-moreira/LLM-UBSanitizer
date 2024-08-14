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
struct i2c_reg_u8 {int /*<<< orphan*/  val; int /*<<< orphan*/  reg; } ;
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_w1 (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void i2c_w1_buf(struct gspca_dev *gspca_dev,
			const struct i2c_reg_u8 *buf, int sz)
{
	while (--sz >= 0) {
		i2c_w1(gspca_dev, buf->reg, buf->val);
		buf++;
	}
}