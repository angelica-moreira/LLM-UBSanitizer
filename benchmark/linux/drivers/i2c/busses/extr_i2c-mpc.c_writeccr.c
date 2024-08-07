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
typedef  int /*<<< orphan*/  u32 ;
struct mpc_i2c {scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ MPC_I2C_CR ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void writeccr(struct mpc_i2c *i2c, u32 x)
{
	writeb(x, i2c->base + MPC_I2C_CR);
}