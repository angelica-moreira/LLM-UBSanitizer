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
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;

/* Variables and functions */
 int /*<<< orphan*/  B43_WARN_ON (int) ; 
#define  NL80211_BAND_2GHZ 129 
#define  NL80211_BAND_5GHZ 128 

__attribute__((used)) static const char *band_to_string(enum nl80211_band band)
{
	switch (band) {
	case NL80211_BAND_5GHZ:
		return "5";
	case NL80211_BAND_2GHZ:
		return "2.4";
	default:
		break;
	}
	B43_WARN_ON(1);
	return "";
}