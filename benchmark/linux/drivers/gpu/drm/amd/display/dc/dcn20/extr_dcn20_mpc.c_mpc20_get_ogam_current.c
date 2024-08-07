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
typedef  int uint32_t ;
struct mpc {int dummy; } ;
struct dcn20_mpc {int dummy; } ;
typedef  enum dc_lut_mode { ____Placeholder_dc_lut_mode } dc_lut_mode ;

/* Variables and functions */
 int LUT_BYPASS ; 
 int LUT_RAM_A ; 
 int LUT_RAM_B ; 
 int /*<<< orphan*/  MPCC_OGAM_CONFIG_STATUS ; 
 int /*<<< orphan*/ * MPCC_OGAM_LUT_RAM_CONTROL ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 struct dcn20_mpc* TO_DCN20_MPC (struct mpc*) ; 

__attribute__((used)) static enum dc_lut_mode mpc20_get_ogam_current(struct mpc *mpc, int mpcc_id)
{
	enum dc_lut_mode mode;
	uint32_t state_mode;
	struct dcn20_mpc *mpc20 = TO_DCN20_MPC(mpc);

	REG_GET(MPCC_OGAM_LUT_RAM_CONTROL[mpcc_id],
			MPCC_OGAM_CONFIG_STATUS, &state_mode);

		switch (state_mode) {
		case 0:
			mode = LUT_BYPASS;
			break;
		case 1:
			mode = LUT_RAM_A;
			break;
		case 2:
			mode = LUT_RAM_B;
			break;
		default:
			mode = LUT_BYPASS;
			break;
		}
		return mode;
}