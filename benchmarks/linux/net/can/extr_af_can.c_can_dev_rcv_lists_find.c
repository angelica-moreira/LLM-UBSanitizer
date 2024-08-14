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
struct net_device {struct can_ml_priv* ml_priv; } ;
struct TYPE_2__ {struct can_dev_rcv_lists* rx_alldev_list; } ;
struct net {TYPE_1__ can; } ;
struct can_dev_rcv_lists {int dummy; } ;
struct can_ml_priv {struct can_dev_rcv_lists dev_rcv_lists; } ;

/* Variables and functions */

__attribute__((used)) static struct can_dev_rcv_lists *can_dev_rcv_lists_find(struct net *net,
							struct net_device *dev)
{
	if (dev) {
		struct can_ml_priv *ml_priv = dev->ml_priv;
		return &ml_priv->dev_rcv_lists;
	} else {
		return net->can.rx_alldev_list;
	}
}