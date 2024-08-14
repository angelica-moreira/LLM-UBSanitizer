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
struct ieee80211_regdomain {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cfg80211_regdomain ; 
 struct ieee80211_regdomain const* rcu_dereference_rtnl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static const struct ieee80211_regdomain *get_cfg80211_regdom(void)
{
	return rcu_dereference_rtnl(cfg80211_regdomain);
}