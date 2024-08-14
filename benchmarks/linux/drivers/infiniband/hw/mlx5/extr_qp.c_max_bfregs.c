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
struct mlx5_ib_dev {int dummy; } ;
struct mlx5_bfreg_info {int dummy; } ;

/* Variables and functions */
 int MLX5_NON_FP_BFREGS_PER_UAR ; 
 int get_num_static_uars (struct mlx5_ib_dev*,struct mlx5_bfreg_info*) ; 

__attribute__((used)) static int max_bfregs(struct mlx5_ib_dev *dev, struct mlx5_bfreg_info *bfregi)
{
	return get_num_static_uars(dev, bfregi) * MLX5_NON_FP_BFREGS_PER_UAR;
}