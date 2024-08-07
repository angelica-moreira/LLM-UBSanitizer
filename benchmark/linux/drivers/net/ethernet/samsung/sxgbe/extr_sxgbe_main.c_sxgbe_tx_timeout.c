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
struct sxgbe_priv_data {int dummy; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct sxgbe_priv_data* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  sxgbe_reset_all_tx_queues (struct sxgbe_priv_data*) ; 

__attribute__((used)) static void sxgbe_tx_timeout(struct net_device *dev)
{
	struct sxgbe_priv_data *priv = netdev_priv(dev);

	sxgbe_reset_all_tx_queues(priv);
}