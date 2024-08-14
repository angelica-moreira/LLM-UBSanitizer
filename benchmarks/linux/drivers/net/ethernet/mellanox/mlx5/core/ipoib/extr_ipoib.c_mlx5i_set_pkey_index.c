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
typedef  scalar_t__ u16 ;
struct net_device {int dummy; } ;
struct mlx5i_priv {scalar_t__ pkey_index; } ;

/* Variables and functions */
 struct mlx5i_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void mlx5i_set_pkey_index(struct net_device *netdev, int id)
{
	struct mlx5i_priv *ipriv = netdev_priv(netdev);

	ipriv->pkey_index = (u16)id;
}