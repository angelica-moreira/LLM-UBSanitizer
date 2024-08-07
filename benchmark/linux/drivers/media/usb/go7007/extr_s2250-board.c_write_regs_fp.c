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
typedef  int u16 ;
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ write_reg_fp (struct i2c_client*,int,int) ; 

__attribute__((used)) static int write_regs_fp(struct i2c_client *client, u16 *regs)
{
	int i;

	for (i = 0; !((regs[i] == 0x00) && (regs[i+1] == 0x00)); i += 2) {
		if (write_reg_fp(client, regs[i], regs[i+1]) < 0) {
			dev_info(&client->dev, "failed fp\n");
			return -1;
		}
	}
	return 0;
}