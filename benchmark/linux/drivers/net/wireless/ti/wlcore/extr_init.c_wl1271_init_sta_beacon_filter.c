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
struct wl12xx_vif {int dummy; } ;
struct wl1271 {int dummy; } ;

/* Variables and functions */
 int wl1271_acx_beacon_filter_opt (struct wl1271*,struct wl12xx_vif*,int) ; 
 int wl1271_acx_beacon_filter_table (struct wl1271*,struct wl12xx_vif*) ; 

__attribute__((used)) static int wl1271_init_sta_beacon_filter(struct wl1271 *wl,
					 struct wl12xx_vif *wlvif)
{
	int ret;

	ret = wl1271_acx_beacon_filter_table(wl, wlvif);
	if (ret < 0)
		return ret;

	/* disable beacon filtering until we get the first beacon */
	ret = wl1271_acx_beacon_filter_opt(wl, wlvif, false);
	if (ret < 0)
		return ret;

	return 0;
}