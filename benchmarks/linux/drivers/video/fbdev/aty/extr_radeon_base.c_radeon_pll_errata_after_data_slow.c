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
struct radeonfb_info {int errata; } ;

/* Variables and functions */
 int CHIP_ERRATA_PLL_DELAY ; 
 int CHIP_ERRATA_R300_CG ; 
 int /*<<< orphan*/  CLOCK_CNTL_DATA ; 
 int /*<<< orphan*/  CLOCK_CNTL_INDEX ; 
 int INREG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OUTREG (int /*<<< orphan*/ ,int) ; 
 int PLL_WR_EN ; 
 int /*<<< orphan*/  _radeon_msleep (struct radeonfb_info*,int) ; 

void radeon_pll_errata_after_data_slow(struct radeonfb_info *rinfo)
{
	if (rinfo->errata & CHIP_ERRATA_PLL_DELAY) {
		/* we can't deal with posted writes here ... */
		_radeon_msleep(rinfo, 5);
	}
	if (rinfo->errata & CHIP_ERRATA_R300_CG) {
		u32 save, tmp;
		save = INREG(CLOCK_CNTL_INDEX);
		tmp = save & ~(0x3f | PLL_WR_EN);
		OUTREG(CLOCK_CNTL_INDEX, tmp);
		tmp = INREG(CLOCK_CNTL_DATA);
		OUTREG(CLOCK_CNTL_INDEX, save);
	}
}