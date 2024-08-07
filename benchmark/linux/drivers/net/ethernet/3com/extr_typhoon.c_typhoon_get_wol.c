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
struct typhoon {int wol_events; } ;
struct net_device {int dummy; } ;
struct ethtool_wolinfo {int supported; int wolopts; int /*<<< orphan*/  sopass; } ;

/* Variables and functions */
 int TYPHOON_WAKE_LINK_EVENT ; 
 int TYPHOON_WAKE_MAGIC_PKT ; 
 int WAKE_MAGIC ; 
 int WAKE_PHY ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 struct typhoon* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void
typhoon_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	struct typhoon *tp = netdev_priv(dev);

	wol->supported = WAKE_PHY | WAKE_MAGIC;
	wol->wolopts = 0;
	if(tp->wol_events & TYPHOON_WAKE_LINK_EVENT)
		wol->wolopts |= WAKE_PHY;
	if(tp->wol_events & TYPHOON_WAKE_MAGIC_PKT)
		wol->wolopts |= WAKE_MAGIC;
	memset(&wol->sopass, 0, sizeof(wol->sopass));
}