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
struct net_device {int tx_queue_len; int /*<<< orphan*/  features; int /*<<< orphan*/  flags; scalar_t__ addr_len; scalar_t__ hard_header_len; int /*<<< orphan*/  mtu; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARPHRD_CAN ; 
 int /*<<< orphan*/  CAN_MTU ; 
 int /*<<< orphan*/  IFF_NOARP ; 
 int /*<<< orphan*/  NETIF_F_HW_CSUM ; 

__attribute__((used)) static void can_setup(struct net_device *dev)
{
	dev->type = ARPHRD_CAN;
	dev->mtu = CAN_MTU;
	dev->hard_header_len = 0;
	dev->addr_len = 0;
	dev->tx_queue_len = 10;

	/* New-style flags. */
	dev->flags = IFF_NOARP;
	dev->features = NETIF_F_HW_CSUM;
}