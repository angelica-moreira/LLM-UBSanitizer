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
struct icn8505_data {int /*<<< orphan*/  client; } ;

/* Variables and functions */
 int /*<<< orphan*/  ICN8505_PROG_I2C_ADDR ; 
 int /*<<< orphan*/  ICN8505_PROG_REG_ADDR_WIDTH ; 
 int icn8505_write_xfer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int icn8505_write_prog_reg(struct icn8505_data *icn8505, int reg, u8 val)
{
	return icn8505_write_xfer(icn8505->client, ICN8505_PROG_I2C_ADDR, reg,
				  ICN8505_PROG_REG_ADDR_WIDTH, &val, 1, false);
}