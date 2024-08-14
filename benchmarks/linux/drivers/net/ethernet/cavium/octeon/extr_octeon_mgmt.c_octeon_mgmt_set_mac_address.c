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

/* Variables and functions */
 int eth_mac_addr (struct net_device*,void*) ; 
 int /*<<< orphan*/  octeon_mgmt_set_rx_filtering (struct net_device*) ; 

__attribute__((used)) static int octeon_mgmt_set_mac_address(struct net_device *netdev, void *addr)
{
	int r = eth_mac_addr(netdev, addr);

	if (r)
		return r;

	octeon_mgmt_set_rx_filtering(netdev);

	return 0;
}