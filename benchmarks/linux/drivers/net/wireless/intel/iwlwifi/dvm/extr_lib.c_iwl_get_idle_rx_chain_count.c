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
struct TYPE_2__ {int smps; } ;
struct iwl_priv {TYPE_1__ current_ht_config; } ;

/* Variables and functions */
#define  IEEE80211_SMPS_AUTOMATIC 131 
#define  IEEE80211_SMPS_DYNAMIC 130 
#define  IEEE80211_SMPS_OFF 129 
#define  IEEE80211_SMPS_STATIC 128 
 int IWL_NUM_IDLE_CHAINS_SINGLE ; 
 int /*<<< orphan*/  WARN (int,char*,int) ; 

__attribute__((used)) static int iwl_get_idle_rx_chain_count(struct iwl_priv *priv, int active_cnt)
{
	/* # Rx chains when idling, depending on SMPS mode */
	switch (priv->current_ht_config.smps) {
	case IEEE80211_SMPS_STATIC:
	case IEEE80211_SMPS_DYNAMIC:
		return IWL_NUM_IDLE_CHAINS_SINGLE;
	case IEEE80211_SMPS_AUTOMATIC:
	case IEEE80211_SMPS_OFF:
		return active_cnt;
	default:
		WARN(1, "invalid SMPS mode %d",
		     priv->current_ht_config.smps);
		return active_cnt;
	}
}