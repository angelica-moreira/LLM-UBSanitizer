#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int u16 ;
struct TYPE_2__ {scalar_t__ type; } ;
struct e1000_hw {TYPE_1__ mac; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  E1000_FEXTNVM4_BEACON_DURATION_16USEC ; 
 int /*<<< orphan*/  E1000_FEXTNVM4_BEACON_DURATION_MASK ; 
 int /*<<< orphan*/  FEXTNVM4 ; 
 int /*<<< orphan*/  HV_M_STATUS ; 
 int HV_M_STATUS_AUTONEG_COMPLETE ; 
 int HV_M_STATUS_LINK_UP ; 
 int HV_M_STATUS_SPEED_100 ; 
 int HV_M_STATUS_SPEED_1000 ; 
 int /*<<< orphan*/  HV_PM_CTRL ; 
 int HV_PM_CTRL_K1_ENABLE ; 
 scalar_t__ e1000_pch2lan ; 
 scalar_t__ e1e_rphy (struct e1000_hw*,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ e1e_wphy (struct e1000_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  er32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ew32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static s32 e1000_k1_workaround_lv(struct e1000_hw *hw)
{
	s32 ret_val = 0;
	u16 status_reg = 0;

	if (hw->mac.type != e1000_pch2lan)
		return 0;

	/* Set K1 beacon duration based on 10Mbs speed */
	ret_val = e1e_rphy(hw, HV_M_STATUS, &status_reg);
	if (ret_val)
		return ret_val;

	if ((status_reg & (HV_M_STATUS_LINK_UP | HV_M_STATUS_AUTONEG_COMPLETE))
	    == (HV_M_STATUS_LINK_UP | HV_M_STATUS_AUTONEG_COMPLETE)) {
		if (status_reg &
		    (HV_M_STATUS_SPEED_1000 | HV_M_STATUS_SPEED_100)) {
			u16 pm_phy_reg;

			/* LV 1G/100 Packet drop issue wa  */
			ret_val = e1e_rphy(hw, HV_PM_CTRL, &pm_phy_reg);
			if (ret_val)
				return ret_val;
			pm_phy_reg &= ~HV_PM_CTRL_K1_ENABLE;
			ret_val = e1e_wphy(hw, HV_PM_CTRL, pm_phy_reg);
			if (ret_val)
				return ret_val;
		} else {
			u32 mac_reg;

			mac_reg = er32(FEXTNVM4);
			mac_reg &= ~E1000_FEXTNVM4_BEACON_DURATION_MASK;
			mac_reg |= E1000_FEXTNVM4_BEACON_DURATION_16USEC;
			ew32(FEXTNVM4, mac_reg);
		}
	}

	return ret_val;
}