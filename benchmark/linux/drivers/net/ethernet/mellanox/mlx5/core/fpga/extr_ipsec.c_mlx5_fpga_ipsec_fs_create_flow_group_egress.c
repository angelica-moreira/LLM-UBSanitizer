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
typedef  int /*<<< orphan*/  u32 ;
struct mlx5_flow_table {int dummy; } ;
struct mlx5_flow_root_namespace {int dummy; } ;
struct mlx5_flow_group {int dummy; } ;

/* Variables and functions */
 int fpga_ipsec_fs_create_flow_group (struct mlx5_flow_root_namespace*,struct mlx5_flow_table*,int /*<<< orphan*/ *,struct mlx5_flow_group*,int) ; 

__attribute__((used)) static int
mlx5_fpga_ipsec_fs_create_flow_group_egress(struct mlx5_flow_root_namespace *ns,
					    struct mlx5_flow_table *ft,
					    u32 *in,
					    struct mlx5_flow_group *fg)
{
	return fpga_ipsec_fs_create_flow_group(ns, ft, in, fg, true);
}