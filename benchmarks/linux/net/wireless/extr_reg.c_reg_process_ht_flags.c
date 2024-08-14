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
struct wiphy {int /*<<< orphan*/ * bands; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;

/* Variables and functions */
 int NUM_NL80211_BANDS ; 
 int /*<<< orphan*/  reg_process_ht_flags_band (struct wiphy*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void reg_process_ht_flags(struct wiphy *wiphy)
{
	enum nl80211_band band;

	if (!wiphy)
		return;

	for (band = 0; band < NUM_NL80211_BANDS; band++)
		reg_process_ht_flags_band(wiphy, wiphy->bands[band]);
}