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
struct sk_buff {int dummy; } ;
struct ieee80211_network {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  tx_ass_rq; } ;
struct ieee80211_device {int /*<<< orphan*/  associate_timer; TYPE_1__ softmac_stats; struct ieee80211_network current_network; } ;

/* Variables and functions */
 int HZ ; 
 int /*<<< orphan*/  IEEE80211_DEBUG_MGMT (char*) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ieee80211_associate_abort (struct ieee80211_device*) ; 
 struct sk_buff* ieee80211_association_req (struct ieee80211_network*,struct ieee80211_device*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  softmac_mgmt_xmit (struct sk_buff*,struct ieee80211_device*) ; 

__attribute__((used)) static void ieee80211_associate_step2(struct ieee80211_device *ieee)
{
	struct sk_buff *skb;
	struct ieee80211_network *beacon = &ieee->current_network;

	del_timer_sync(&ieee->associate_timer);

	IEEE80211_DEBUG_MGMT("Sending association request\n");

	ieee->softmac_stats.tx_ass_rq++;
	skb = ieee80211_association_req(beacon, ieee);
	if (!skb) {
		ieee80211_associate_abort(ieee);
	} else {
		softmac_mgmt_xmit(skb, ieee);
		mod_timer(&ieee->associate_timer, jiffies + (HZ / 2));
		//dev_kfree_skb_any(skb);//edit by thomas
	}
}