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
struct cpsw_sl {scalar_t__* regs; scalar_t__ sl_base; int /*<<< orphan*/  dev; } ;
typedef  enum cpsw_sl_regs { ____Placeholder_cpsw_sl_regs } cpsw_sl_regs ;

/* Variables and functions */
 scalar_t__ CPSW_SL_REG_NOTUSED ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,scalar_t__,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int readl (scalar_t__) ; 

u32 cpsw_sl_reg_read(struct cpsw_sl *sl, enum cpsw_sl_regs reg)
{
	int val;

	if (sl->regs[reg] == CPSW_SL_REG_NOTUSED) {
		dev_err(sl->dev, "cpsw_sl: not sup r reg: %04X\n",
			sl->regs[reg]);
		return 0;
	}

	val = readl(sl->sl_base + sl->regs[reg]);
	dev_dbg(sl->dev, "cpsw_sl: reg: %04X r 0x%08X\n", sl->regs[reg], val);
	return val;
}