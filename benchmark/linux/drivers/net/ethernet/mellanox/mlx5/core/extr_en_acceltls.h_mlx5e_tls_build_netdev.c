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
struct mlx5e_priv {int /*<<< orphan*/  mdev; } ;

/* Variables and functions */
 scalar_t__ mlx5_accel_is_ktls_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5e_ktls_build_netdev (struct mlx5e_priv*) ; 

__attribute__((used)) static inline void mlx5e_tls_build_netdev(struct mlx5e_priv *priv)
{
	if (mlx5_accel_is_ktls_device(priv->mdev))
		mlx5e_ktls_build_netdev(priv);
}