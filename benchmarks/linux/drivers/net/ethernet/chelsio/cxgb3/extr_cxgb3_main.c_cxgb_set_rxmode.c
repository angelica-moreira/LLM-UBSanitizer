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
struct port_info {int /*<<< orphan*/  mac; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct port_info* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  t3_mac_set_rx_mode (int /*<<< orphan*/ *,struct net_device*) ; 

__attribute__((used)) static void cxgb_set_rxmode(struct net_device *dev)
{
	struct port_info *pi = netdev_priv(dev);

	t3_mac_set_rx_mode(&pi->mac, dev);
}