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
struct device {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static bool vc5_regmap_is_writeable(struct device *dev, unsigned int reg)
{
	/* Factory reserved regs, make them read-only */
	if (reg <= 0xf)
		return false;

	/* Factory reserved regs, make them read-only */
	if (reg == 0x14 || reg == 0x1c || reg == 0x1d)
		return false;

	return true;
}