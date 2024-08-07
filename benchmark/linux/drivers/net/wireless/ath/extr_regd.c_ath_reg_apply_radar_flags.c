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
struct wiphy {struct ieee80211_supported_band** bands; } ;
struct ieee80211_supported_band {unsigned int n_channels; struct ieee80211_channel* channels; } ;
struct ieee80211_channel {int flags; int /*<<< orphan*/  center_freq; } ;
struct ath_regulatory {int dummy; } ;

/* Variables and functions */
 int IEEE80211_CHAN_DISABLED ; 
 int IEEE80211_CHAN_NO_IR ; 
 int IEEE80211_CHAN_RADAR ; 
 size_t NL80211_BAND_5GHZ ; 
 int /*<<< orphan*/  ath_is_radar_freq (int /*<<< orphan*/ ,struct ath_regulatory*) ; 

__attribute__((used)) static void ath_reg_apply_radar_flags(struct wiphy *wiphy,
				      struct ath_regulatory *reg)
{
	struct ieee80211_supported_band *sband;
	struct ieee80211_channel *ch;
	unsigned int i;

	if (!wiphy->bands[NL80211_BAND_5GHZ])
		return;

	sband = wiphy->bands[NL80211_BAND_5GHZ];

	for (i = 0; i < sband->n_channels; i++) {
		ch = &sband->channels[i];
		if (!ath_is_radar_freq(ch->center_freq, reg))
			continue;
		/* We always enable radar detection/DFS on this
		 * frequency range. Additionally we also apply on
		 * this frequency range:
		 * - If STA mode does not yet have DFS supports disable
		 *   active scanning
		 * - If adhoc mode does not support DFS yet then
		 *   disable adhoc in the frequency.
		 * - If AP mode does not yet support radar detection/DFS
		 *   do not allow AP mode
		 */
		if (!(ch->flags & IEEE80211_CHAN_DISABLED))
			ch->flags |= IEEE80211_CHAN_RADAR |
				     IEEE80211_CHAN_NO_IR;
	}
}