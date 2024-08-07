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
struct tun_struct {int /*<<< orphan*/  link_ksettings; } ;
struct net_device {int dummy; } ;
struct ethtool_link_ksettings {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (struct ethtool_link_ksettings*,int /*<<< orphan*/ *,int) ; 
 struct tun_struct* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int tun_get_link_ksettings(struct net_device *dev,
				  struct ethtool_link_ksettings *cmd)
{
	struct tun_struct *tun = netdev_priv(dev);

	memcpy(cmd, &tun->link_ksettings, sizeof(*cmd));
	return 0;
}