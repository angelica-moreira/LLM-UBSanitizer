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
struct ieee80211_device {int /*<<< orphan*/ * networks; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void ieee80211_networks_free(struct ieee80211_device *ieee)
{
	if (!ieee->networks)
		return;
	kfree(ieee->networks);
	ieee->networks = NULL;
}