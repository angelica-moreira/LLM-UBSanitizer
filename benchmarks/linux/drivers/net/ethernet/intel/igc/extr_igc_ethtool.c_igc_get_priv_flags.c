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
struct igc_adapter {int flags; } ;

/* Variables and functions */
 int IGC_FLAG_RX_LEGACY ; 
 int /*<<< orphan*/  IGC_PRIV_FLAGS_LEGACY_RX ; 
 struct igc_adapter* netdev_priv (struct net_device*) ; 

__attribute__((used)) static u32 igc_get_priv_flags(struct net_device *netdev)
{
	struct igc_adapter *adapter = netdev_priv(netdev);
	u32 priv_flags = 0;

	if (adapter->flags & IGC_FLAG_RX_LEGACY)
		priv_flags |= IGC_PRIV_FLAGS_LEGACY_RX;

	return priv_flags;
}