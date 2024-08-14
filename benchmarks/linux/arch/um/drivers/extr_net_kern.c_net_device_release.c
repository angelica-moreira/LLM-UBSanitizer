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
struct uml_net_private {int /*<<< orphan*/  user; int /*<<< orphan*/  (* remove ) (int /*<<< orphan*/ *) ;} ;
struct uml_net {int /*<<< orphan*/  list; struct net_device* dev; } ;
struct net_device {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct uml_net* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 int /*<<< orphan*/  kfree (struct uml_net*) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 struct uml_net_private* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void net_device_release(struct device *dev)
{
	struct uml_net *device = dev_get_drvdata(dev);
	struct net_device *netdev = device->dev;
	struct uml_net_private *lp = netdev_priv(netdev);

	if (lp->remove != NULL)
		(*lp->remove)(&lp->user);
	list_del(&device->list);
	kfree(device);
	free_netdev(netdev);
}