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
struct rhine_private {int /*<<< orphan*/  mii_if; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mii_link_ok (int /*<<< orphan*/ *) ; 
 struct rhine_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static u32 netdev_get_link(struct net_device *dev)
{
	struct rhine_private *rp = netdev_priv(dev);

	return mii_link_ok(&rp->mii_if);
}