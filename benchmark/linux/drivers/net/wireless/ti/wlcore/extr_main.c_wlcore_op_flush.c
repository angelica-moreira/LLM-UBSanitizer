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
typedef  int /*<<< orphan*/  u32 ;
struct wl1271 {int dummy; } ;
struct ieee80211_vif {int dummy; } ;
struct ieee80211_hw {struct wl1271* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  wl1271_tx_flush (struct wl1271*) ; 

__attribute__((used)) static void wlcore_op_flush(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
			    u32 queues, bool drop)
{
	struct wl1271 *wl = hw->priv;

	wl1271_tx_flush(wl);
}