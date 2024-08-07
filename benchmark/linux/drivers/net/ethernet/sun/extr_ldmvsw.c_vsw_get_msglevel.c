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
typedef  int /*<<< orphan*/  u32 ;
struct vnet_port {TYPE_1__* vp; } ;
struct net_device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  msg_enable; } ;

/* Variables and functions */
 struct vnet_port* netdev_priv (struct net_device*) ; 

__attribute__((used)) static u32 vsw_get_msglevel(struct net_device *dev)
{
	struct vnet_port *port = netdev_priv(dev);

	return port->vp->msg_enable;
}