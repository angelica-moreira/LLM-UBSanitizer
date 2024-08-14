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
struct mlx5e_priv {int dummy; } ;
struct ethtool_flash {int dummy; } ;

/* Variables and functions */
 int mlx5e_ethtool_flash_device (struct mlx5e_priv*,struct ethtool_flash*) ; 
 struct mlx5e_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int mlx5e_flash_device(struct net_device *dev,
			      struct ethtool_flash *flash)
{
	struct mlx5e_priv *priv = netdev_priv(dev);

	return mlx5e_ethtool_flash_device(priv, flash);
}