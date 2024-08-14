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
typedef  scalar_t__ u8 ;
struct dig_t {scalar_t__ cur_cck_cca_thres; scalar_t__ pre_cck_cca_thres; } ;
struct rtl_priv {struct dig_t dm_digtable; } ;
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DM_REG_CCK_CCA_11N ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 
 int /*<<< orphan*/  rtl_write_byte (struct rtl_priv*,int /*<<< orphan*/ ,scalar_t__) ; 

void rtl92ee_dm_write_cck_cca_thres(struct ieee80211_hw *hw, u8 cur_thres)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct dig_t *dm_dig = &rtlpriv->dm_digtable;

	if (dm_dig->cur_cck_cca_thres != cur_thres)
		rtl_write_byte(rtlpriv, DM_REG_CCK_CCA_11N, cur_thres);

	dm_dig->pre_cck_cca_thres = dm_dig->cur_cck_cca_thres;
	dm_dig->cur_cck_cca_thres = cur_thres;
}