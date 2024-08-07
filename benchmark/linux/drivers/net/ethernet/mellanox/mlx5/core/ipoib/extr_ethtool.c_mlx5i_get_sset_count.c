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

/* Variables and functions */
 int mlx5e_ethtool_get_sset_count (struct mlx5e_priv*,int) ; 
 struct mlx5e_priv* mlx5i_epriv (struct net_device*) ; 

__attribute__((used)) static int mlx5i_get_sset_count(struct net_device *dev, int sset)
{
	struct mlx5e_priv *priv = mlx5i_epriv(dev);

	return mlx5e_ethtool_get_sset_count(priv, sset);
}