#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct net_device {int* dev_addr; } ;
struct ioc3_private {TYPE_1__* regs; } ;
struct TYPE_2__ {int /*<<< orphan*/  emar_l; int /*<<< orphan*/  emar_h; } ;

/* Variables and functions */
 struct ioc3_private* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void __ioc3_set_mac_address(struct net_device *dev)
{
	struct ioc3_private *ip = netdev_priv(dev);

	writel((dev->dev_addr[5] <<  8) |
	       dev->dev_addr[4],
	       &ip->regs->emar_h);
	writel((dev->dev_addr[3] << 24) |
	       (dev->dev_addr[2] << 16) |
	       (dev->dev_addr[1] <<  8) |
	       dev->dev_addr[0],
	       &ip->regs->emar_l);
}