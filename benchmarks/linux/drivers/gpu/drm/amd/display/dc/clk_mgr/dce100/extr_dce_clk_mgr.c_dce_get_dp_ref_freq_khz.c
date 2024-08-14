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
struct clk_mgr_internal {int dentist_vco_freq_khz; } ;
struct clk_mgr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  DENTIST_DISPCLK_CNTL ; 
 int DENTIST_DIVIDER_RANGE_SCALE_FACTOR ; 
 int /*<<< orphan*/  DENTIST_DPREFCLK_WDIVIDER ; 
 int /*<<< orphan*/  DPREFCLK_CNTL ; 
 int /*<<< orphan*/  DPREFCLK_SRC_SEL ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 struct clk_mgr_internal* TO_CLK_MGR_INTERNAL (struct clk_mgr*) ; 
 int dce_adjust_dp_ref_freq_for_ss (struct clk_mgr_internal*,int) ; 
 int dentist_get_divider_from_did (int) ; 

int dce_get_dp_ref_freq_khz(struct clk_mgr *clk_mgr_base)
{
	struct clk_mgr_internal *clk_mgr = TO_CLK_MGR_INTERNAL(clk_mgr_base);
	int dprefclk_wdivider;
	int dprefclk_src_sel;
	int dp_ref_clk_khz = 600000;
	int target_div;

	/* ASSERT DP Reference Clock source is from DFS*/
	REG_GET(DPREFCLK_CNTL, DPREFCLK_SRC_SEL, &dprefclk_src_sel);
	ASSERT(dprefclk_src_sel == 0);

	/* Read the mmDENTIST_DISPCLK_CNTL to get the currently
	 * programmed DID DENTIST_DPREFCLK_WDIVIDER*/
	REG_GET(DENTIST_DISPCLK_CNTL, DENTIST_DPREFCLK_WDIVIDER, &dprefclk_wdivider);

	/* Convert DENTIST_DPREFCLK_WDIVIDERto actual divider*/
	target_div = dentist_get_divider_from_did(dprefclk_wdivider);

	/* Calculate the current DFS clock, in kHz.*/
	dp_ref_clk_khz = (DENTIST_DIVIDER_RANGE_SCALE_FACTOR
		* clk_mgr->dentist_vco_freq_khz) / target_div;

	return dce_adjust_dp_ref_freq_for_ss(clk_mgr, dp_ref_clk_khz);
}