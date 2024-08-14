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
struct net_device {scalar_t__ addr_len; int /*<<< orphan*/  uc; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  __dev_set_rx_mode (struct net_device*) ; 
 int __hw_addr_sync_multiple (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  netif_addr_lock (struct net_device*) ; 
 int /*<<< orphan*/  netif_addr_unlock (struct net_device*) ; 

int dev_uc_sync_multiple(struct net_device *to, struct net_device *from)
{
	int err = 0;

	if (to->addr_len != from->addr_len)
		return -EINVAL;

	netif_addr_lock(to);
	err = __hw_addr_sync_multiple(&to->uc, &from->uc, to->addr_len);
	if (!err)
		__dev_set_rx_mode(to);
	netif_addr_unlock(to);
	return err;
}