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
struct mb862xxfb_par {int dummy; } ;
struct i2c_adapter {struct mb862xxfb_par* algo_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  GC_I2C_BCR ; 
 int /*<<< orphan*/  GC_I2C_DAR ; 
 int I2C_ACK ; 
 int I2C_START ; 
 int /*<<< orphan*/  i2c ; 
 int /*<<< orphan*/  inreg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb862xx_i2c_wait_event (struct i2c_adapter*) ; 
 int /*<<< orphan*/  outreg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int mb862xx_i2c_read_byte(struct i2c_adapter *adap, u8 *byte, int last)
{
	struct mb862xxfb_par *par = adap->algo_data;

	outreg(i2c, GC_I2C_BCR, I2C_START | (last ? 0 : I2C_ACK));
	if (!mb862xx_i2c_wait_event(adap))
		return 0;
	*byte = inreg(i2c, GC_I2C_DAR);
	return 1;
}