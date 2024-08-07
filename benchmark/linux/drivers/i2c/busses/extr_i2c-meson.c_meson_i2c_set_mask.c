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
struct meson_i2c {scalar_t__ regs; } ;

/* Variables and functions */
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static void meson_i2c_set_mask(struct meson_i2c *i2c, int reg, u32 mask,
			       u32 val)
{
	u32 data;

	data = readl(i2c->regs + reg);
	data &= ~mask;
	data |= val & mask;
	writel(data, i2c->regs + reg);
}