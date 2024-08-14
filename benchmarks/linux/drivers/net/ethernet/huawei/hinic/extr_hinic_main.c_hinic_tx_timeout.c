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
struct net_device {int dummy; } ;
struct hinic_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drv ; 
 struct hinic_dev* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_err (struct hinic_dev*,int /*<<< orphan*/ ,struct net_device*,char*) ; 

__attribute__((used)) static void hinic_tx_timeout(struct net_device *netdev)
{
	struct hinic_dev *nic_dev = netdev_priv(netdev);

	netif_err(nic_dev, drv, netdev, "Tx timeout\n");
}