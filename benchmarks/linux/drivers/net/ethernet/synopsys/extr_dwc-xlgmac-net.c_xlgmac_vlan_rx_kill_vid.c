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
typedef  int /*<<< orphan*/  u16 ;
struct xlgmac_hw_ops {int /*<<< orphan*/  (* update_vlan_hash_table ) (struct xlgmac_pdata*) ;} ;
struct xlgmac_pdata {int /*<<< orphan*/  active_vlans; struct xlgmac_hw_ops hw_ops; } ;
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct xlgmac_pdata* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  stub1 (struct xlgmac_pdata*) ; 

__attribute__((used)) static int xlgmac_vlan_rx_kill_vid(struct net_device *netdev,
				   __be16 proto,
				   u16 vid)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);
	struct xlgmac_hw_ops *hw_ops = &pdata->hw_ops;

	clear_bit(vid, pdata->active_vlans);
	hw_ops->update_vlan_hash_table(pdata);

	return 0;
}