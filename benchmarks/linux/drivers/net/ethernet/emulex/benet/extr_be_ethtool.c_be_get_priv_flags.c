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
struct be_adapter {int /*<<< orphan*/  priv_flags; } ;

/* Variables and functions */
 struct be_adapter* netdev_priv (struct net_device*) ; 

__attribute__((used)) static u32 be_get_priv_flags(struct net_device *netdev)
{
	struct be_adapter *adapter = netdev_priv(netdev);

	return adapter->priv_flags;
}