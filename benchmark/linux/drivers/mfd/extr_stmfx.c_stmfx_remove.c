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
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int stmfx_chip_exit (struct i2c_client*) ; 
 int /*<<< orphan*/  stmfx_irq_exit (struct i2c_client*) ; 

__attribute__((used)) static int stmfx_remove(struct i2c_client *client)
{
	stmfx_irq_exit(client);

	return stmfx_chip_exit(client);
}