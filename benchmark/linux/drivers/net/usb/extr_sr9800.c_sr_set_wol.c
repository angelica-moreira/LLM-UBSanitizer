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
typedef  int /*<<< orphan*/  u8 ;
struct usbnet {int dummy; } ;
struct net_device {int dummy; } ;
struct ethtool_wolinfo {int wolopts; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  SR_CMD_WRITE_MONITOR_MODE ; 
 int /*<<< orphan*/  SR_MONITOR_LINK ; 
 int /*<<< orphan*/  SR_MONITOR_MAGIC ; 
 int WAKE_MAGIC ; 
 int WAKE_PHY ; 
 struct usbnet* netdev_priv (struct net_device*) ; 
 scalar_t__ sr_write_cmd (struct usbnet*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
sr_set_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
	struct usbnet *dev = netdev_priv(net);
	u8 opt = 0;

	if (wolinfo->wolopts & ~(WAKE_PHY | WAKE_MAGIC))
		return -EINVAL;

	if (wolinfo->wolopts & WAKE_PHY)
		opt |= SR_MONITOR_LINK;
	if (wolinfo->wolopts & WAKE_MAGIC)
		opt |= SR_MONITOR_MAGIC;

	if (sr_write_cmd(dev, SR_CMD_WRITE_MONITOR_MODE,
			 opt, 0, 0, NULL) < 0)
		return -EINVAL;

	return 0;
}