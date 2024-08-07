#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct ttc_params {int /*<<< orphan*/ * indir_tirn; } ;
struct TYPE_7__ {int /*<<< orphan*/  inner_ttc; int /*<<< orphan*/  ttc; int /*<<< orphan*/  ns; } ;
struct mlx5e_priv {TYPE_3__ fs; TYPE_4__* netdev; TYPE_2__* indir_tir; TYPE_1__* inner_indir_tir; int /*<<< orphan*/  mdev; } ;
struct TYPE_8__ {int /*<<< orphan*/  hw_features; } ;
struct TYPE_6__ {int /*<<< orphan*/  tirn; } ;
struct TYPE_5__ {int /*<<< orphan*/  tirn; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int MLX5E_NUM_INDIR_TIRS ; 
 int /*<<< orphan*/  MLX5_FLOW_NAMESPACE_KERNEL ; 
 int /*<<< orphan*/  NETIF_F_NTUPLE ; 
 int /*<<< orphan*/  mlx5_get_flow_namespace (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mlx5e_arfs_create_tables (struct mlx5e_priv*) ; 
 int /*<<< orphan*/  mlx5e_arfs_destroy_tables (struct mlx5e_priv*) ; 
 int mlx5e_create_inner_ttc_table (struct mlx5e_priv*,struct ttc_params*,int /*<<< orphan*/ *) ; 
 int mlx5e_create_l2_table (struct mlx5e_priv*) ; 
 int mlx5e_create_ttc_table (struct mlx5e_priv*,struct ttc_params*,int /*<<< orphan*/ *) ; 
 int mlx5e_create_vlan_table (struct mlx5e_priv*) ; 
 int /*<<< orphan*/  mlx5e_destroy_inner_ttc_table (struct mlx5e_priv*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mlx5e_destroy_l2_table (struct mlx5e_priv*) ; 
 int /*<<< orphan*/  mlx5e_destroy_ttc_table (struct mlx5e_priv*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mlx5e_ethtool_init_steering (struct mlx5e_priv*) ; 
 int /*<<< orphan*/  mlx5e_set_inner_ttc_ft_params (struct ttc_params*) ; 
 int /*<<< orphan*/  mlx5e_set_ttc_basic_params (struct mlx5e_priv*,struct ttc_params*) ; 
 int /*<<< orphan*/  mlx5e_set_ttc_ft_params (struct ttc_params*) ; 
 int /*<<< orphan*/  netdev_err (TYPE_4__*,char*,int) ; 

int mlx5e_create_flow_steering(struct mlx5e_priv *priv)
{
	struct ttc_params ttc_params = {};
	int tt, err;

	priv->fs.ns = mlx5_get_flow_namespace(priv->mdev,
					       MLX5_FLOW_NAMESPACE_KERNEL);

	if (!priv->fs.ns)
		return -EOPNOTSUPP;

	err = mlx5e_arfs_create_tables(priv);
	if (err) {
		netdev_err(priv->netdev, "Failed to create arfs tables, err=%d\n",
			   err);
		priv->netdev->hw_features &= ~NETIF_F_NTUPLE;
	}

	mlx5e_set_ttc_basic_params(priv, &ttc_params);
	mlx5e_set_inner_ttc_ft_params(&ttc_params);
	for (tt = 0; tt < MLX5E_NUM_INDIR_TIRS; tt++)
		ttc_params.indir_tirn[tt] = priv->inner_indir_tir[tt].tirn;

	err = mlx5e_create_inner_ttc_table(priv, &ttc_params, &priv->fs.inner_ttc);
	if (err) {
		netdev_err(priv->netdev, "Failed to create inner ttc table, err=%d\n",
			   err);
		goto err_destroy_arfs_tables;
	}

	mlx5e_set_ttc_ft_params(&ttc_params);
	for (tt = 0; tt < MLX5E_NUM_INDIR_TIRS; tt++)
		ttc_params.indir_tirn[tt] = priv->indir_tir[tt].tirn;

	err = mlx5e_create_ttc_table(priv, &ttc_params, &priv->fs.ttc);
	if (err) {
		netdev_err(priv->netdev, "Failed to create ttc table, err=%d\n",
			   err);
		goto err_destroy_inner_ttc_table;
	}

	err = mlx5e_create_l2_table(priv);
	if (err) {
		netdev_err(priv->netdev, "Failed to create l2 table, err=%d\n",
			   err);
		goto err_destroy_ttc_table;
	}

	err = mlx5e_create_vlan_table(priv);
	if (err) {
		netdev_err(priv->netdev, "Failed to create vlan table, err=%d\n",
			   err);
		goto err_destroy_l2_table;
	}

	mlx5e_ethtool_init_steering(priv);

	return 0;

err_destroy_l2_table:
	mlx5e_destroy_l2_table(priv);
err_destroy_ttc_table:
	mlx5e_destroy_ttc_table(priv, &priv->fs.ttc);
err_destroy_inner_ttc_table:
	mlx5e_destroy_inner_ttc_table(priv, &priv->fs.inner_ttc);
err_destroy_arfs_tables:
	mlx5e_arfs_destroy_tables(priv);

	return err;
}