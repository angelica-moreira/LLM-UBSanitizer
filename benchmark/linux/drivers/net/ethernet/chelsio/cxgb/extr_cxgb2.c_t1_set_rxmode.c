#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct t1_rx_mode {struct net_device* dev; } ;
struct net_device {size_t if_port; struct adapter* ml_priv; } ;
struct cmac {TYPE_2__* ops; } ;
struct adapter {TYPE_1__* port; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* set_rx_mode ) (struct cmac*,struct t1_rx_mode*) ;} ;
struct TYPE_3__ {struct cmac* mac; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct cmac*,struct t1_rx_mode*) ; 

__attribute__((used)) static void t1_set_rxmode(struct net_device *dev)
{
	struct adapter *adapter = dev->ml_priv;
	struct cmac *mac = adapter->port[dev->if_port].mac;
	struct t1_rx_mode rm;

	rm.dev = dev;
	mac->ops->set_rx_mode(mac, &rm);
}