#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct TYPE_8__ {TYPE_1__* chan; } ;
struct TYPE_9__ {TYPE_2__ chandef; } ;
struct mt7603_dev {TYPE_3__ mt76; } ;
struct ieee80211_tx_rate {int flags; int idx; } ;
struct ieee80211_rate {int hw_value_short; int hw_value; } ;
struct TYPE_12__ {TYPE_5__* wiphy; } ;
struct TYPE_11__ {TYPE_4__** bands; } ;
struct TYPE_10__ {struct ieee80211_rate* bitrates; } ;
struct TYPE_7__ {int band; } ;

/* Variables and functions */
 int FIELD_PREP (int /*<<< orphan*/ ,int) ; 
 int IEEE80211_TX_RC_40_MHZ_WIDTH ; 
 int IEEE80211_TX_RC_GREEN_FIELD ; 
 int IEEE80211_TX_RC_MCS ; 
 int IEEE80211_TX_RC_USE_SHORT_PREAMBLE ; 
 int MT_PHY_TYPE_HT ; 
 int MT_PHY_TYPE_HT_GF ; 
 int /*<<< orphan*/  MT_TX_RATE_IDX ; 
 int /*<<< orphan*/  MT_TX_RATE_MODE ; 
 int MT_TX_RATE_STBC ; 
 TYPE_6__* mt76_hw (struct mt7603_dev*) ; 

__attribute__((used)) static u16
mt7603_mac_tx_rate_val(struct mt7603_dev *dev,
		       const struct ieee80211_tx_rate *rate, bool stbc, u8 *bw)
{
	u8 phy, nss, rate_idx;
	u16 rateval;

	*bw = 0;
	if (rate->flags & IEEE80211_TX_RC_MCS) {
		rate_idx = rate->idx;
		nss = 1 + (rate->idx >> 3);
		phy = MT_PHY_TYPE_HT;
		if (rate->flags & IEEE80211_TX_RC_GREEN_FIELD)
			phy = MT_PHY_TYPE_HT_GF;
		if (rate->flags & IEEE80211_TX_RC_40_MHZ_WIDTH)
			*bw = 1;
	} else {
		const struct ieee80211_rate *r;
		int band = dev->mt76.chandef.chan->band;
		u16 val;

		nss = 1;
		r = &mt76_hw(dev)->wiphy->bands[band]->bitrates[rate->idx];
		if (rate->flags & IEEE80211_TX_RC_USE_SHORT_PREAMBLE)
			val = r->hw_value_short;
		else
			val = r->hw_value;

		phy = val >> 8;
		rate_idx = val & 0xff;
	}

	rateval = (FIELD_PREP(MT_TX_RATE_IDX, rate_idx) |
		   FIELD_PREP(MT_TX_RATE_MODE, phy));

	if (stbc && nss == 1)
		rateval |= MT_TX_RATE_STBC;

	return rateval;
}