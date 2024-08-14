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
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int cx25840_read4 (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int cx25840_write4 (struct i2c_client*,int /*<<< orphan*/ ,int) ; 

int cx25840_and_or4(struct i2c_client *client, u16 addr, u32 and_mask,
		    u32 or_value)
{
	return cx25840_write4(client, addr,
			      (cx25840_read4(client, addr) & and_mask) |
			      or_value);
}