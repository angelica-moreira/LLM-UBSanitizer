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
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  _rtl8723be_phy_convert_txpower_dbm_to_relative_value (struct ieee80211_hw*) ; 
 int /*<<< orphan*/  _rtl8723be_phy_store_txpower_by_rate_base (struct ieee80211_hw*) ; 

__attribute__((used)) static void phy_txpower_by_rate_config(struct ieee80211_hw *hw)
{
	_rtl8723be_phy_store_txpower_by_rate_base(hw);
	_rtl8723be_phy_convert_txpower_dbm_to_relative_value(hw);
}