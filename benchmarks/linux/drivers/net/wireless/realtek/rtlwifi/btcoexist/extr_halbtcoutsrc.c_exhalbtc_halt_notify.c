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
struct TYPE_2__ {int btdm_ant_num; } ;
struct btc_coexist {int binded; TYPE_1__ board_info; int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 scalar_t__ IS_HARDWARE_TYPE_8192E (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_HARDWARE_TYPE_8723B (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_HARDWARE_TYPE_8821 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ex_btc8192e2ant_halt_notify (struct btc_coexist*) ; 
 int /*<<< orphan*/  ex_btc8723b1ant_halt_notify (struct btc_coexist*) ; 
 int /*<<< orphan*/  ex_btc8723b2ant_halt_notify (struct btc_coexist*) ; 
 int /*<<< orphan*/  ex_btc8821a1ant_halt_notify (struct btc_coexist*) ; 
 int /*<<< orphan*/  ex_btc8821a2ant_halt_notify (struct btc_coexist*) ; 
 int /*<<< orphan*/  halbtc_is_bt_coexist_available (struct btc_coexist*) ; 

void exhalbtc_halt_notify(struct btc_coexist *btcoexist)
{
	if (!halbtc_is_bt_coexist_available(btcoexist))
		return;

	if (IS_HARDWARE_TYPE_8821(btcoexist->adapter)) {
		if (btcoexist->board_info.btdm_ant_num == 2)
			ex_btc8821a2ant_halt_notify(btcoexist);
		else if (btcoexist->board_info.btdm_ant_num == 1)
			ex_btc8821a1ant_halt_notify(btcoexist);
	} else if (IS_HARDWARE_TYPE_8723B(btcoexist->adapter)) {
		if (btcoexist->board_info.btdm_ant_num == 2)
			ex_btc8723b2ant_halt_notify(btcoexist);
		else if (btcoexist->board_info.btdm_ant_num == 1)
			ex_btc8723b1ant_halt_notify(btcoexist);
	} else if (IS_HARDWARE_TYPE_8192E(btcoexist->adapter)) {
		if (btcoexist->board_info.btdm_ant_num == 2)
			ex_btc8192e2ant_halt_notify(btcoexist);
	}

	btcoexist->binded = false;
}