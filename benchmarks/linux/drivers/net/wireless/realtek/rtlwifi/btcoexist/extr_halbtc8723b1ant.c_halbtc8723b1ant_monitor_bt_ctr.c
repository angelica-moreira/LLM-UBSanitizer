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
typedef  int u32 ;
struct btc_coexist {int (* btc_read_4byte ) (struct btc_coexist*,int) ;int /*<<< orphan*/  (* btc_write_1byte ) (struct btc_coexist*,int,int) ;} ;
struct TYPE_2__ {int high_priority_tx; int high_priority_rx; int low_priority_tx; int low_priority_rx; int /*<<< orphan*/  pop_event_cnt; int /*<<< orphan*/  c2h_bt_inquiry_page; } ;

/* Variables and functions */
 int MASKHWORD ; 
 int MASKLWORD ; 
 TYPE_1__* coex_sta ; 
 int /*<<< orphan*/  halbtc8723b1ant_query_bt_info (struct btc_coexist*) ; 
 int stub1 (struct btc_coexist*,int) ; 
 int stub2 (struct btc_coexist*,int) ; 
 int /*<<< orphan*/  stub3 (struct btc_coexist*,int,int) ; 

__attribute__((used)) static void halbtc8723b1ant_monitor_bt_ctr(struct btc_coexist *btcoexist)
{
	u32 reg_hp_txrx, reg_lp_txrx, u32tmp;
	u32 reg_hp_tx = 0, reg_hp_rx = 0;
	u32 reg_lp_tx = 0, reg_lp_rx = 0;
	static u32 num_of_bt_counter_chk;

	reg_hp_txrx = 0x770;
	reg_lp_txrx = 0x774;

	u32tmp = btcoexist->btc_read_4byte(btcoexist, reg_hp_txrx);
	reg_hp_tx = u32tmp & MASKLWORD;
	reg_hp_rx = (u32tmp & MASKHWORD) >> 16;

	u32tmp = btcoexist->btc_read_4byte(btcoexist, reg_lp_txrx);
	reg_lp_tx = u32tmp & MASKLWORD;
	reg_lp_rx = (u32tmp & MASKHWORD) >> 16;

	coex_sta->high_priority_tx = reg_hp_tx;
	coex_sta->high_priority_rx = reg_hp_rx;
	coex_sta->low_priority_tx = reg_lp_tx;
	coex_sta->low_priority_rx = reg_lp_rx;

	if ((coex_sta->low_priority_tx > 1050) &&
	    (!coex_sta->c2h_bt_inquiry_page))
		coex_sta->pop_event_cnt++;

	/* reset counter */
	btcoexist->btc_write_1byte(btcoexist, 0x76e, 0xc);

	/* This part is for wifi FW and driver to update BT's status as
	 * disabled.
	 *
	 * The flow is as the following
	 * 1. disable BT
	 * 2. if all BT Tx/Rx counter = 0, after 6 sec we query bt info
	 * 3. Because BT will not rsp from mailbox, so wifi fw will know BT is
	 * disabled
	 *
	 * 4. FW will rsp c2h for BT that driver will know BT is disabled.
	 */
	if ((reg_hp_tx == 0) && (reg_hp_rx == 0) && (reg_lp_tx == 0) &&
	    (reg_lp_rx == 0)) {
		num_of_bt_counter_chk++;
		if (num_of_bt_counter_chk == 3)
			halbtc8723b1ant_query_bt_info(btcoexist);
	} else {
		num_of_bt_counter_chk = 0;
	}
}