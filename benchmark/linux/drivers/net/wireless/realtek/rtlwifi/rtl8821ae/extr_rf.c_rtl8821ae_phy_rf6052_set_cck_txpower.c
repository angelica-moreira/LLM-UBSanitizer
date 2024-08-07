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
typedef  size_t u8 ;
typedef  int u32 ;
struct rtl_phy {int** mcs_txpwrlevel_origoffset; } ;
struct rtl_priv {struct rtl_phy phy; } ;
struct rtl_mac {scalar_t__ act_scanning; } ;
struct rtl_efuse {scalar_t__ eeprom_regulatory; } ;
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FPHY ; 
 int /*<<< orphan*/  MASKDWORD ; 
 int /*<<< orphan*/  PHY_TXPWR ; 
 size_t RF6052_MAX_TX_PWR ; 
 size_t RF90_PATH_A ; 
 size_t RF90_PATH_B ; 
 int /*<<< orphan*/  RTPRINT (struct rtl_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RTXAGC_A_CCK11_CCK1 ; 
 int /*<<< orphan*/  RTXAGC_B_CCK11_CCK1 ; 
 int /*<<< orphan*/  rtl8821ae_dm_txpower_track_adjust (struct ieee80211_hw*,int,size_t*,int*) ; 
 struct rtl_efuse* rtl_efuse (struct rtl_priv*) ; 
 struct rtl_mac* rtl_mac (struct rtl_priv*) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 
 int /*<<< orphan*/  rtl_set_bbreg (struct ieee80211_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

void rtl8821ae_phy_rf6052_set_cck_txpower(struct ieee80211_hw *hw,
					  u8 *ppowerlevel)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &rtlpriv->phy;
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u32 tx_agc[2] = {0, 0}, tmpval;
	bool turbo_scanoff = false;
	u8 idx1, idx2;
	u8 *ptr;
	u8 direction;
	u32 pwrtrac_value;

	if (rtlefuse->eeprom_regulatory != 0)
		turbo_scanoff = true;

	if (mac->act_scanning) {
		tx_agc[RF90_PATH_A] = 0x3f3f3f3f;
		tx_agc[RF90_PATH_B] = 0x3f3f3f3f;

		if (turbo_scanoff) {
			for (idx1 = RF90_PATH_A;
				idx1 <= RF90_PATH_B;
				idx1++) {
				tx_agc[idx1] = ppowerlevel[idx1] |
				    (ppowerlevel[idx1] << 8) |
				    (ppowerlevel[idx1] << 16) |
				    (ppowerlevel[idx1] << 24);
			}
		}
	} else {
		for (idx1 = RF90_PATH_A; idx1 <= RF90_PATH_B; idx1++) {
			tx_agc[idx1] = ppowerlevel[idx1] |
			    (ppowerlevel[idx1] << 8) |
			    (ppowerlevel[idx1] << 16) |
			    (ppowerlevel[idx1] << 24);
		}

		if (rtlefuse->eeprom_regulatory == 0) {
			tmpval =
			    (rtlphy->mcs_txpwrlevel_origoffset[0][6]) +
			    (rtlphy->mcs_txpwrlevel_origoffset[0][7] <<
			     8);
			tx_agc[RF90_PATH_A] += tmpval;

			tmpval = (rtlphy->mcs_txpwrlevel_origoffset[0][14]) +
			    (rtlphy->mcs_txpwrlevel_origoffset[0][15] <<
			     24);
			tx_agc[RF90_PATH_B] += tmpval;
		}
	}

	for (idx1 = RF90_PATH_A; idx1 <= RF90_PATH_B; idx1++) {
		ptr = (u8 *)(&tx_agc[idx1]);
		for (idx2 = 0; idx2 < 4; idx2++) {
			if (*ptr > RF6052_MAX_TX_PWR)
				*ptr = RF6052_MAX_TX_PWR;
			ptr++;
		}
	}
	rtl8821ae_dm_txpower_track_adjust(hw, 1, &direction, &pwrtrac_value);
	if (direction == 1) {
		tx_agc[0] += pwrtrac_value;
		tx_agc[1] += pwrtrac_value;
	} else if (direction == 2) {
		tx_agc[0] -= pwrtrac_value;
		tx_agc[1] -= pwrtrac_value;
	}
	tmpval = tx_agc[RF90_PATH_A];
	rtl_set_bbreg(hw, RTXAGC_A_CCK11_CCK1, MASKDWORD, tmpval);

	RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
		"CCK PWR 1~11M (rf-A) = 0x%x (reg 0x%x)\n", tmpval,
		 RTXAGC_A_CCK11_CCK1);

	tmpval = tx_agc[RF90_PATH_B];
	rtl_set_bbreg(hw, RTXAGC_B_CCK11_CCK1, MASKDWORD, tmpval);

	RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
		"CCK PWR 11M (rf-B) = 0x%x (reg 0x%x)\n", tmpval,
		 RTXAGC_B_CCK11_CCK1);
}