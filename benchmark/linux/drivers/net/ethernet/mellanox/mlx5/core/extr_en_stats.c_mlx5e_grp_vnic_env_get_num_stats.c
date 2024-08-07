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
 int NUM_VNIC_ENV_DEV_OOB_COUNTERS (int /*<<< orphan*/ ) ; 
 int NUM_VNIC_ENV_STEER_COUNTERS (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlx5e_grp_vnic_env_get_num_stats(struct mlx5e_priv *priv)
{
	return NUM_VNIC_ENV_STEER_COUNTERS(priv->mdev) +
		NUM_VNIC_ENV_DEV_OOB_COUNTERS(priv->mdev);
}