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

/* Variables and functions */
 int /*<<< orphan*/  NDS32_CCTL_L1D_IX_RWD ; 
 int /*<<< orphan*/  __nds32__cctl_l1d_wball_one_lvl () ; 
 int /*<<< orphan*/  __nds32__cctlidx_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void cpu_dcache_wb_all(void)
{
	__nds32__cctl_l1d_wball_one_lvl();
	__nds32__cctlidx_read(NDS32_CCTL_L1D_IX_RWD,0);
}