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
typedef  int /*<<< orphan*/  u64 ;
struct net_device {int dummy; } ;
struct mlx5e_priv {int dummy; } ;
struct ethtool_stats {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5e_ethtool_get_ethtool_stats (struct mlx5e_priv*,struct ethtool_stats*,int /*<<< orphan*/ *) ; 
 struct mlx5e_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void mlx5e_get_ethtool_stats(struct net_device *dev,
				    struct ethtool_stats *stats,
				    u64 *data)
{
	struct mlx5e_priv *priv = netdev_priv(dev);

	mlx5e_ethtool_get_ethtool_stats(priv, stats, data);
}