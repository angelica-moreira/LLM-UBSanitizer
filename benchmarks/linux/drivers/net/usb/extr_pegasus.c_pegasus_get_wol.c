#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct net_device {int dummy; } ;
struct ethtool_wolinfo {int supported; int /*<<< orphan*/  wolopts; } ;
struct TYPE_3__ {int /*<<< orphan*/  wolopts; } ;
typedef  TYPE_1__ pegasus_t ;

/* Variables and functions */
 int WAKE_MAGIC ; 
 int WAKE_PHY ; 
 TYPE_1__* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void
pegasus_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	pegasus_t	*pegasus = netdev_priv(dev);

	wol->supported = WAKE_MAGIC | WAKE_PHY;
	wol->wolopts = pegasus->wolopts;
}