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
typedef  int u8 ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int i2c_smbus_write_byte_data (struct i2c_client*,int const,int const) ; 

__attribute__((used)) static int write_regs(struct i2c_client *client, const u8 *regs, u8 channel)
{
	int ret;
	int i;

	for (i = 0; regs[i] != 0xff; i += 2) {
		ret = i2c_smbus_write_byte_data(client,
				regs[i] | (channel << 6), regs[i + 1]);
		if (ret < 0)
			return ret;
	}
	return 0;
}