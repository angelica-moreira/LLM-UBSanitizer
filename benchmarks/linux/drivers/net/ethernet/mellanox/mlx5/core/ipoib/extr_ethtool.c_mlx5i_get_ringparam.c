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
struct ethtool_ringparam {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5e_ethtool_get_ringparam (struct mlx5e_priv*,struct ethtool_ringparam*) ; 
 struct mlx5e_priv* mlx5i_epriv (struct net_device*) ; 

__attribute__((used)) static void mlx5i_get_ringparam(struct net_device *dev,
				struct ethtool_ringparam *param)
{
	struct mlx5e_priv *priv = mlx5i_epriv(dev);

	mlx5e_ethtool_get_ringparam(priv, param);
}