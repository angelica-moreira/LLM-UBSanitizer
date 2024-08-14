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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct fs_enet_private {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 struct fs_enet_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void ev_error(struct net_device *dev, u32 int_events)
{
	struct fs_enet_private *fep = netdev_priv(dev);

	dev_warn(fep->dev, "FEC ERROR(s) 0x%x\n", int_events);
}