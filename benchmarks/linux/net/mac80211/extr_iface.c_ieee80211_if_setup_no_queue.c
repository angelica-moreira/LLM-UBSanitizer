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
struct net_device {int /*<<< orphan*/  priv_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  IFF_NO_QUEUE ; 
 int /*<<< orphan*/  ieee80211_if_setup (struct net_device*) ; 

__attribute__((used)) static void ieee80211_if_setup_no_queue(struct net_device *dev)
{
	ieee80211_if_setup(dev);
	dev->priv_flags |= IFF_NO_QUEUE;
}