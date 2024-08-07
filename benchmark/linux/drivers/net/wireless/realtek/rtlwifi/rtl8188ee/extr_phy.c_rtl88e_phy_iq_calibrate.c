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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct rtl_phy {long reg_eb4; long reg_ebc; long reg_e94; long reg_e9c; int /*<<< orphan*/  iqk_bb_backup; TYPE_1__* iqk_matrix; } ;
struct rtl_priv {struct rtl_phy phy; } ;
struct ieee80211_hw {int dummy; } ;
struct TYPE_2__ {long** value; int iqk_done; } ;

/* Variables and functions */
 int IQK_MATRIX_REG_NUM ; 
 scalar_t__ RF_2T2R ; 
 int /*<<< orphan*/  ROFDM0_AGCRSSITABLE ; 
 int /*<<< orphan*/  ROFDM0_ECCATHRESHOLD ; 
 int /*<<< orphan*/  ROFDM0_RXIQEXTANTA ; 
 int /*<<< orphan*/  ROFDM0_XARXIQIMBALANCE ; 
 int /*<<< orphan*/  ROFDM0_XATXIQIMBALANCE ; 
 int /*<<< orphan*/  ROFDM0_XBRXIQIMBALANCE ; 
 int /*<<< orphan*/  ROFDM0_XBTXIQIMBALANCE ; 
 int /*<<< orphan*/  ROFDM0_XCTXAFE ; 
 int /*<<< orphan*/  ROFDM0_XDTXAFE ; 
 int /*<<< orphan*/  _rtl88e_phy_iq_calibrate (struct ieee80211_hw*,long**,int,int) ; 
 int /*<<< orphan*/  _rtl88e_phy_path_a_fill_iqk_matrix (struct ieee80211_hw*,int,long**,int,int) ; 
 int /*<<< orphan*/  _rtl88e_phy_reload_adda_registers (struct ieee80211_hw*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  _rtl88e_phy_save_adda_registers (struct ieee80211_hw*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int _rtl88e_phy_simularity_compare (struct ieee80211_hw*,long**,int,int) ; 
 scalar_t__ get_rf_type (struct rtl_phy*) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 

void rtl88e_phy_iq_calibrate(struct ieee80211_hw *hw, bool b_recovery)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &rtlpriv->phy;
	long result[4][8];
	u8 i, final_candidate;
	bool b_patha_ok, b_pathb_ok;
	long reg_e94, reg_e9c, reg_ea4, reg_eac, reg_eb4, reg_ebc, reg_ec4,
	    reg_ecc, reg_tmp = 0;
	bool is12simular, is13simular, is23simular;
	u32 iqk_bb_reg[9] = {
		ROFDM0_XARXIQIMBALANCE,
		ROFDM0_XBRXIQIMBALANCE,
		ROFDM0_ECCATHRESHOLD,
		ROFDM0_AGCRSSITABLE,
		ROFDM0_XATXIQIMBALANCE,
		ROFDM0_XBTXIQIMBALANCE,
		ROFDM0_XCTXAFE,
		ROFDM0_XDTXAFE,
		ROFDM0_RXIQEXTANTA
	};

	if (b_recovery) {
		_rtl88e_phy_reload_adda_registers(hw,
						  iqk_bb_reg,
						  rtlphy->iqk_bb_backup, 9);
		return;
	}

	for (i = 0; i < 8; i++) {
		result[0][i] = 0;
		result[1][i] = 0;
		result[2][i] = 0;
		result[3][i] = 0;
	}
	final_candidate = 0xff;
	b_patha_ok = false;
	b_pathb_ok = false;
	is12simular = false;
	is23simular = false;
	is13simular = false;
	for (i = 0; i < 3; i++) {
		if (get_rf_type(rtlphy) == RF_2T2R)
			_rtl88e_phy_iq_calibrate(hw, result, i, true);
		else
			_rtl88e_phy_iq_calibrate(hw, result, i, false);
		if (i == 1) {
			is12simular =
			  _rtl88e_phy_simularity_compare(hw, result, 0, 1);
			if (is12simular) {
				final_candidate = 0;
				break;
			}
		}
		if (i == 2) {
			is13simular =
			  _rtl88e_phy_simularity_compare(hw, result, 0, 2);
			if (is13simular) {
				final_candidate = 0;
				break;
			}
			is23simular =
			   _rtl88e_phy_simularity_compare(hw, result, 1, 2);
			if (is23simular) {
				final_candidate = 1;
			} else {
				for (i = 0; i < 8; i++)
					reg_tmp += result[3][i];

				if (reg_tmp != 0)
					final_candidate = 3;
				else
					final_candidate = 0xFF;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		reg_e94 = result[i][0];
		reg_e9c = result[i][1];
		reg_ea4 = result[i][2];
		reg_eac = result[i][3];
		reg_eb4 = result[i][4];
		reg_ebc = result[i][5];
		reg_ec4 = result[i][6];
		reg_ecc = result[i][7];
	}
	if (final_candidate != 0xff) {
		reg_e94 = result[final_candidate][0];
		reg_e9c = result[final_candidate][1];
		reg_ea4 = result[final_candidate][2];
		reg_eac = result[final_candidate][3];
		reg_eb4 = result[final_candidate][4];
		reg_ebc = result[final_candidate][5];
		reg_ec4 = result[final_candidate][6];
		reg_ecc = result[final_candidate][7];
		rtlphy->reg_eb4 = reg_eb4;
		rtlphy->reg_ebc = reg_ebc;
		rtlphy->reg_e94 = reg_e94;
		rtlphy->reg_e9c = reg_e9c;
		b_patha_ok = true;
		b_pathb_ok = true;
	} else {
		rtlphy->reg_e94 = 0x100;
		rtlphy->reg_eb4 = 0x100;
		rtlphy->reg_e9c = 0x0;
		rtlphy->reg_ebc = 0x0;
	}
	if (reg_e94 != 0) /*&&(reg_ea4 != 0) */
		_rtl88e_phy_path_a_fill_iqk_matrix(hw, b_patha_ok, result,
						   final_candidate,
						   (reg_ea4 == 0));
	if (final_candidate != 0xFF) {
		for (i = 0; i < IQK_MATRIX_REG_NUM; i++)
			rtlphy->iqk_matrix[0].value[0][i] =
				result[final_candidate][i];
		rtlphy->iqk_matrix[0].iqk_done = true;

	}
	_rtl88e_phy_save_adda_registers(hw, iqk_bb_reg,
					rtlphy->iqk_bb_backup, 9);
}