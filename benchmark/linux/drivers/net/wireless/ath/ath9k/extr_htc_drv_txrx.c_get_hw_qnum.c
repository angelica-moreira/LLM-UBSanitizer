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
typedef  int u16 ;

/* Variables and functions */
 size_t IEEE80211_AC_BE ; 
 size_t IEEE80211_AC_BK ; 
 size_t IEEE80211_AC_VI ; 
 size_t IEEE80211_AC_VO ; 

int get_hw_qnum(u16 queue, int *hwq_map)
{
	switch (queue) {
	case 0:
		return hwq_map[IEEE80211_AC_VO];
	case 1:
		return hwq_map[IEEE80211_AC_VI];
	case 2:
		return hwq_map[IEEE80211_AC_BE];
	case 3:
		return hwq_map[IEEE80211_AC_BK];
	default:
		return hwq_map[IEEE80211_AC_BE];
	}
}