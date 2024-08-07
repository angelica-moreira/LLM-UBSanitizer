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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct ep93xx_priv {int /*<<< orphan*/  mii; } ;

/* Variables and functions */
 int /*<<< orphan*/  mii_link_ok (int /*<<< orphan*/ *) ; 
 struct ep93xx_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static u32 ep93xx_get_link(struct net_device *dev)
{
	struct ep93xx_priv *ep = netdev_priv(dev);
	return mii_link_ok(&ep->mii);
}