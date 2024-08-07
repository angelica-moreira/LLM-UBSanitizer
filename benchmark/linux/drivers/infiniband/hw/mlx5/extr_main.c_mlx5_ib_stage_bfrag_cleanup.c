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
struct mlx5_ib_dev {int /*<<< orphan*/  bfreg; int /*<<< orphan*/  mdev; int /*<<< orphan*/  fp_bfreg; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5_free_bfreg (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mlx5_ib_stage_bfrag_cleanup(struct mlx5_ib_dev *dev)
{
	mlx5_free_bfreg(dev->mdev, &dev->fp_bfreg);
	mlx5_free_bfreg(dev->mdev, &dev->bfreg);
}