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
 int /*<<< orphan*/  bcm_enet_mdio_write (int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  netdev_priv (struct net_device*) ; 

__attribute__((used)) static void bcm_enet_mdio_write_mii(struct net_device *dev, int mii_id,
				    int regnum, int value)
{
	bcm_enet_mdio_write(netdev_priv(dev), mii_id, regnum, value);
}