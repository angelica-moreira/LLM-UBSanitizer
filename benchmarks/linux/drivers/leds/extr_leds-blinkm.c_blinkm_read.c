#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct i2c_client {int dummy; } ;
struct TYPE_2__ {int nr_ret; } ;

/* Variables and functions */
 TYPE_1__* blinkm_cmds ; 
 int i2c_smbus_read_byte (struct i2c_client*) ; 

__attribute__((used)) static int blinkm_read(struct i2c_client *client, int cmd, u8 *arg)
{
	int result;
	int i;
	int retlen = blinkm_cmds[cmd].nr_ret;
	for (i = 0; i < retlen; i++) {
		/* repeat for retlen */
		result = i2c_smbus_read_byte(client);
		if (result < 0)
			return result;
		arg[i] = result;
	}

	return 0;
}