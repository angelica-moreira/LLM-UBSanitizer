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
struct wireless_dev {int dummy; } ;
struct wiphy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ieee80211_scan_cancel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wiphy_priv (struct wiphy*) ; 

__attribute__((used)) static void ieee80211_abort_scan(struct wiphy *wiphy, struct wireless_dev *wdev)
{
	ieee80211_scan_cancel(wiphy_priv(wiphy));
}