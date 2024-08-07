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
typedef  int /*<<< orphan*/  u8 ;
typedef  scalar_t__ u32 ;
struct btc_coexist {int /*<<< orphan*/  (* btc_get ) (struct btc_coexist*,int /*<<< orphan*/ ,scalar_t__*) ;int /*<<< orphan*/  (* btc_set_rf_reg ) (struct btc_coexist*,int /*<<< orphan*/ ,int,int,int) ;} ;
struct TYPE_2__ {scalar_t__ switch_thres_offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTC_GET_U4_WIFI_BW ; 
 int /*<<< orphan*/  BTC_RF_A ; 
 scalar_t__ BTC_RSSI_HIGH (int /*<<< orphan*/ ) ; 
 scalar_t__ BTC_WIFI_BW_HT40 ; 
 scalar_t__ BTC_WIFI_BW_LEGACY ; 
 scalar_t__ BT_8723B_2ANT_BT_RSSI_COEXSWITCH_THRES ; 
 int /*<<< orphan*/  NORMAL_EXEC ; 
 int /*<<< orphan*/  btc8723b2ant_bt_rssi_state (struct btc_coexist*,int,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  btc8723b2ant_coex_table_with_type (struct btc_coexist*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  btc8723b2ant_dec_bt_pwr (struct btc_coexist*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  btc8723b2ant_fw_dac_swing_lvl (struct btc_coexist*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  btc8723b2ant_limited_rx (struct btc_coexist*,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  btc8723b2ant_ps_tdma (struct btc_coexist*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  btc8723b2ant_sw_mechanism (struct btc_coexist*,int,int,int,int) ; 
 int /*<<< orphan*/  btc8723b2ant_wifi_rssi_state (struct btc_coexist*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 TYPE_1__* coex_dm ; 
 int /*<<< orphan*/  stub1 (struct btc_coexist*,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  stub2 (struct btc_coexist*,int /*<<< orphan*/ ,scalar_t__*) ; 

__attribute__((used)) static void btc8723b2ant_action_sco(struct btc_coexist *btcoexist)
{
	u8 wifi_rssi_state, bt_rssi_state;
	u32 wifi_bw;

	wifi_rssi_state = btc8723b2ant_wifi_rssi_state(btcoexist, 0, 2, 15, 0);
	bt_rssi_state = btc8723b2ant_bt_rssi_state(
		btcoexist, 2, BT_8723B_2ANT_BT_RSSI_COEXSWITCH_THRES -
					       coex_dm->switch_thres_offset,
		0);

	btcoexist->btc_set_rf_reg(btcoexist, BTC_RF_A, 0x1, 0xfffff, 0x0);

	btc8723b2ant_limited_rx(btcoexist, NORMAL_EXEC, false, false, 0x8);
	btc8723b2ant_fw_dac_swing_lvl(btcoexist, NORMAL_EXEC, 4);

	if (BTC_RSSI_HIGH(bt_rssi_state))
		btc8723b2ant_dec_bt_pwr(btcoexist, NORMAL_EXEC, 2);
	else
		btc8723b2ant_dec_bt_pwr(btcoexist, NORMAL_EXEC, 0);

	btcoexist->btc_get(btcoexist, BTC_GET_U4_WIFI_BW, &wifi_bw);

	if (BTC_WIFI_BW_LEGACY == wifi_bw)
		/* for SCO quality at 11b/g mode */
		btc8723b2ant_coex_table_with_type(btcoexist, NORMAL_EXEC, 2);
	else
		/* for SCO quality & wifi performance balance at 11n mode */
		btc8723b2ant_coex_table_with_type(btcoexist, NORMAL_EXEC, 8);

	/* for voice quality */
	btc8723b2ant_ps_tdma(btcoexist, NORMAL_EXEC, false, 0);

	/* sw mechanism */
	if (BTC_WIFI_BW_HT40 == wifi_bw) {
		btc8723b2ant_sw_mechanism(btcoexist, true, true,
					  false, false);
	} else {
		btc8723b2ant_sw_mechanism(btcoexist, false, true,
					  false, false);
	}
}