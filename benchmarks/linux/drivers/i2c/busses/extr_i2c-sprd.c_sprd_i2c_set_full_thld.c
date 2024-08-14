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
struct sprd_i2c {scalar_t__ base; } ;

/* Variables and functions */
 int FIFO_AF_LVL ; 
 int FIFO_AF_LVL_MASK ; 
 scalar_t__ I2C_CTL ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void sprd_i2c_set_full_thld(struct sprd_i2c *i2c_dev, u32 full_thld)
{
	u32 tmp = readl(i2c_dev->base + I2C_CTL);

	tmp &= ~FIFO_AF_LVL_MASK;
	tmp |= full_thld << FIFO_AF_LVL;
	writel(tmp, i2c_dev->base + I2C_CTL);
}