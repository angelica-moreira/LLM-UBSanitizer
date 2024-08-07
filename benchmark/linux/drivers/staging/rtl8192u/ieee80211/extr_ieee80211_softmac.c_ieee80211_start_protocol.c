#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {short channel; int beacon_interval; } ;
struct ieee80211_device {int proto_started; int* last_rxseq_num; int* last_rxfrag_num; scalar_t__ iw_mode; scalar_t__ init_wmmparam_flag; scalar_t__* last_packet_time; TYPE_1__ current_network; } ;
struct TYPE_4__ {int /*<<< orphan*/ * channel_map; } ;

/* Variables and functions */
 TYPE_2__* GET_DOT11D_INFO (struct ieee80211_device*) ; 
 scalar_t__ IW_MODE_ADHOC ; 
 scalar_t__ IW_MODE_INFRA ; 
 scalar_t__ IW_MODE_MASTER ; 
 scalar_t__ IW_MODE_MONITOR ; 
 short MAX_CHANNEL_NUMBER ; 
 int /*<<< orphan*/  ieee80211_start_bss (struct ieee80211_device*) ; 
 int /*<<< orphan*/  ieee80211_start_ibss (struct ieee80211_device*) ; 
 int /*<<< orphan*/  ieee80211_start_master_bss (struct ieee80211_device*) ; 
 int /*<<< orphan*/  ieee80211_start_monitor_mode (struct ieee80211_device*) ; 

void ieee80211_start_protocol(struct ieee80211_device *ieee)
{
	short ch = 0;
	int i = 0;

	if (ieee->proto_started)
		return;

	ieee->proto_started = 1;

	if (ieee->current_network.channel == 0) {
		do {
			ch++;
			if (ch > MAX_CHANNEL_NUMBER)
				return; /* no channel found */
		} while (!GET_DOT11D_INFO(ieee)->channel_map[ch]);
		ieee->current_network.channel = ch;
	}

	if (ieee->current_network.beacon_interval == 0)
		ieee->current_network.beacon_interval = 100;
//	printk("===>%s(), chan:%d\n", __func__, ieee->current_network.channel);
//	ieee->set_chan(ieee->dev,ieee->current_network.channel);

	for (i = 0; i < 17; i++) {
		ieee->last_rxseq_num[i] = -1;
		ieee->last_rxfrag_num[i] = -1;
		ieee->last_packet_time[i] = 0;
	}

	ieee->init_wmmparam_flag = 0;//reinitialize AC_xx_PARAM registers.

	/* if the user set the MAC of the ad-hoc cell and then
	 * switch to managed mode, shall we  make sure that association
	 * attempts does not fail just because the user provide the essid
	 * and the nic is still checking for the AP MAC ??
	 */
	if (ieee->iw_mode == IW_MODE_INFRA)
		ieee80211_start_bss(ieee);

	else if (ieee->iw_mode == IW_MODE_ADHOC)
		ieee80211_start_ibss(ieee);

	else if (ieee->iw_mode == IW_MODE_MASTER)
		ieee80211_start_master_bss(ieee);

	else if (ieee->iw_mode == IW_MODE_MONITOR)
		ieee80211_start_monitor_mode(ieee);
}