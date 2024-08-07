#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct ieee80211_sub_if_data {struct ieee80211_local* local; } ;
struct TYPE_9__ {int /*<<< orphan*/  ssid_len; int /*<<< orphan*/  ssid; } ;
struct TYPE_8__ {TYPE_2__* wiphy; } ;
struct ieee80211_local {int /*<<< orphan*/  mtx; TYPE_5__* int_scan_req; TYPE_4__ scan_ssid; TYPE_3__ hw; scalar_t__ scan_req; } ;
struct ieee80211_channel {int flags; } ;
typedef  enum nl80211_bss_scan_width { ____Placeholder_nl80211_bss_scan_width } nl80211_bss_scan_width ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
struct TYPE_10__ {int n_channels; int n_ssids; int scan_width; TYPE_4__* ssids; struct ieee80211_channel** channels; } ;
struct TYPE_7__ {TYPE_1__** bands; } ;
struct TYPE_6__ {int n_channels; struct ieee80211_channel* channels; } ;

/* Variables and functions */
 int EBUSY ; 
 int IEEE80211_CHAN_DISABLED ; 
 int IEEE80211_CHAN_NO_IR ; 
 int /*<<< orphan*/  IEEE80211_MAX_SSID_LEN ; 
 int NUM_NL80211_BANDS ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int __ieee80211_start_scan (struct ieee80211_sub_if_data*,TYPE_5__*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int ieee80211_request_ibss_scan(struct ieee80211_sub_if_data *sdata,
				const u8 *ssid, u8 ssid_len,
				struct ieee80211_channel **channels,
				unsigned int n_channels,
				enum nl80211_bss_scan_width scan_width)
{
	struct ieee80211_local *local = sdata->local;
	int ret = -EBUSY, i, n_ch = 0;
	enum nl80211_band band;

	mutex_lock(&local->mtx);

	/* busy scanning */
	if (local->scan_req)
		goto unlock;

	/* fill internal scan request */
	if (!channels) {
		int max_n;

		for (band = 0; band < NUM_NL80211_BANDS; band++) {
			if (!local->hw.wiphy->bands[band])
				continue;

			max_n = local->hw.wiphy->bands[band]->n_channels;
			for (i = 0; i < max_n; i++) {
				struct ieee80211_channel *tmp_ch =
				    &local->hw.wiphy->bands[band]->channels[i];

				if (tmp_ch->flags & (IEEE80211_CHAN_NO_IR |
						     IEEE80211_CHAN_DISABLED))
					continue;

				local->int_scan_req->channels[n_ch] = tmp_ch;
				n_ch++;
			}
		}

		if (WARN_ON_ONCE(n_ch == 0))
			goto unlock;

		local->int_scan_req->n_channels = n_ch;
	} else {
		for (i = 0; i < n_channels; i++) {
			if (channels[i]->flags & (IEEE80211_CHAN_NO_IR |
						  IEEE80211_CHAN_DISABLED))
				continue;

			local->int_scan_req->channels[n_ch] = channels[i];
			n_ch++;
		}

		if (WARN_ON_ONCE(n_ch == 0))
			goto unlock;

		local->int_scan_req->n_channels = n_ch;
	}

	local->int_scan_req->ssids = &local->scan_ssid;
	local->int_scan_req->n_ssids = 1;
	local->int_scan_req->scan_width = scan_width;
	memcpy(local->int_scan_req->ssids[0].ssid, ssid, IEEE80211_MAX_SSID_LEN);
	local->int_scan_req->ssids[0].ssid_len = ssid_len;

	ret = __ieee80211_start_scan(sdata, sdata->local->int_scan_req);
 unlock:
	mutex_unlock(&local->mtx);
	return ret;
}