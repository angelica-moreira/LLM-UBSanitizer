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
struct ieee80211_device {int /*<<< orphan*/  beacon_lock; int /*<<< orphan*/  beacon_timer; scalar_t__ beacon_txing; } ;

/* Variables and functions */
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void ieee80211_beacons_stop(struct ieee80211_device *ieee)
{
	unsigned long flags;

	spin_lock_irqsave(&ieee->beacon_lock, flags);

	ieee->beacon_txing = 0;
	del_timer_sync(&ieee->beacon_timer);

	spin_unlock_irqrestore(&ieee->beacon_lock, flags);
}