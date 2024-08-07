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
struct ieee80211_vif {int dummy; } ;
struct ieee80211_sta {scalar_t__ drv_priv; } ;
struct ieee80211_hw {struct ath_softc* priv; } ;
struct ath_softc {int /*<<< orphan*/  sc_ah; } ;
struct ath_node {int sleeping; } ;
typedef  enum sta_notify_cmd { ____Placeholder_sta_notify_cmd } sta_notify_cmd ;

/* Variables and functions */
#define  STA_NOTIFY_AWAKE 129 
#define  STA_NOTIFY_SLEEP 128 
 int /*<<< orphan*/  ath9k_sta_set_tx_filter (int /*<<< orphan*/ ,struct ath_node*,int) ; 
 int /*<<< orphan*/  ath_tx_aggr_sleep (struct ieee80211_sta*,struct ath_softc*,struct ath_node*) ; 
 int /*<<< orphan*/  ath_tx_aggr_wakeup (struct ath_softc*,struct ath_node*) ; 

__attribute__((used)) static void ath9k_sta_notify(struct ieee80211_hw *hw,
			 struct ieee80211_vif *vif,
			 enum sta_notify_cmd cmd,
			 struct ieee80211_sta *sta)
{
	struct ath_softc *sc = hw->priv;
	struct ath_node *an = (struct ath_node *) sta->drv_priv;

	switch (cmd) {
	case STA_NOTIFY_SLEEP:
		an->sleeping = true;
		ath_tx_aggr_sleep(sta, sc, an);
		ath9k_sta_set_tx_filter(sc->sc_ah, an, true);
		break;
	case STA_NOTIFY_AWAKE:
		ath9k_sta_set_tx_filter(sc->sc_ah, an, false);
		an->sleeping = false;
		ath_tx_aggr_wakeup(sc, an);
		break;
	}
}