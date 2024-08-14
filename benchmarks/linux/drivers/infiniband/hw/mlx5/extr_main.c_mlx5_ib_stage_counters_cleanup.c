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
struct mlx5_ib_dev {int /*<<< orphan*/  mdev; } ;

/* Variables and functions */
 scalar_t__ MLX5_CAP_GEN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  max_qp_cnt ; 
 int /*<<< orphan*/  mlx5_ib_dealloc_counters (struct mlx5_ib_dev*) ; 

__attribute__((used)) static void mlx5_ib_stage_counters_cleanup(struct mlx5_ib_dev *dev)
{
	if (MLX5_CAP_GEN(dev->mdev, max_qp_cnt))
		mlx5_ib_dealloc_counters(dev);
}