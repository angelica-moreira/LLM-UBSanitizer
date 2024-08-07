#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  tx_errors; } ;
struct net_device {TYPE_1__ stats; } ;
struct TYPE_6__ {int /*<<< orphan*/  tx_urb; } ;
typedef  TYPE_2__ pegasus_t ;

/* Variables and functions */
 TYPE_2__* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_warn (TYPE_2__*,int /*<<< orphan*/ ,struct net_device*,char*) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  usb_unlink_urb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pegasus_tx_timeout(struct net_device *net)
{
	pegasus_t *pegasus = netdev_priv(net);
	netif_warn(pegasus, timer, net, "tx timeout\n");
	usb_unlink_urb(pegasus->tx_urb);
	net->stats.tx_errors++;
}