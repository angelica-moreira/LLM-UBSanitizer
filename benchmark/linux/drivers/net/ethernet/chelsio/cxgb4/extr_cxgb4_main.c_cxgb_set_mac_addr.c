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
struct sockaddr {int /*<<< orphan*/  sa_data; } ;
struct port_info {int xact_addr_filt; int /*<<< orphan*/  smt_idx; int /*<<< orphan*/  viid; } ;
struct net_device {int /*<<< orphan*/  addr_len; int /*<<< orphan*/  dev_addr; } ;

/* Variables and functions */
 int EADDRNOTAVAIL ; 
 int cxgb4_update_mac_filt (struct port_info*,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  is_valid_ether_addr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct port_info* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int cxgb_set_mac_addr(struct net_device *dev, void *p)
{
	int ret;
	struct sockaddr *addr = p;
	struct port_info *pi = netdev_priv(dev);

	if (!is_valid_ether_addr(addr->sa_data))
		return -EADDRNOTAVAIL;

	ret = cxgb4_update_mac_filt(pi, pi->viid, &pi->xact_addr_filt,
				    addr->sa_data, true, &pi->smt_idx);
	if (ret < 0)
		return ret;

	memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
	pi->xact_addr_filt = ret;
	return 0;
}