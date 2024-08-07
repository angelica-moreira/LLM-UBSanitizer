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
struct tun_struct {int /*<<< orphan*/  rx_batched; } ;
struct net_device {int dummy; } ;
struct ethtool_coalesce {int /*<<< orphan*/  rx_max_coalesced_frames; } ;

/* Variables and functions */
 struct tun_struct* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int tun_get_coalesce(struct net_device *dev,
			    struct ethtool_coalesce *ec)
{
	struct tun_struct *tun = netdev_priv(dev);

	ec->rx_max_coalesced_frames = tun->rx_batched;

	return 0;
}