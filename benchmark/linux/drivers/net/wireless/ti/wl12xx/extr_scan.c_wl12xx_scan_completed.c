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
 int /*<<< orphan*/  wl1271_scan_stm (struct wl1271*,struct wl12xx_vif*) ; 

void wl12xx_scan_completed(struct wl1271 *wl, struct wl12xx_vif *wlvif)
{
	wl1271_scan_stm(wl, wlvif);
}