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
struct netlink_ext_ack {int dummy; } ;
struct net_device {int dummy; } ;
struct mlx5e_priv {int dummy; } ;
struct mlx5e_encap_entry {int /*<<< orphan*/  reformat_type; int /*<<< orphan*/ * tunnel; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLX5_REFORMAT_TYPE_L2_TO_VXLAN ; 
 int /*<<< orphan*/  geneve_tunnel ; 

__attribute__((used)) static int mlx5e_tc_tun_init_encap_attr_geneve(struct net_device *tunnel_dev,
					       struct mlx5e_priv *priv,
					       struct mlx5e_encap_entry *e,
					       struct netlink_ext_ack *extack)
{
	e->tunnel = &geneve_tunnel;

	/* Reformat type for GENEVE encap is similar to VXLAN:
	 * in both cases the HW adds in the same place a
	 * defined encapsulation header that the SW provides.
	 */
	e->reformat_type = MLX5_REFORMAT_TYPE_L2_TO_VXLAN;
	return 0;
}