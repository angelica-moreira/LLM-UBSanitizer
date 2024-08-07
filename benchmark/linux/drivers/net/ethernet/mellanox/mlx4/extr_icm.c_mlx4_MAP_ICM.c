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
typedef  int /*<<< orphan*/  u64 ;
struct mlx4_icm {int dummy; } ;
struct mlx4_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLX4_CMD_MAP_ICM ; 
 int mlx4_map_cmd (struct mlx4_dev*,int /*<<< orphan*/ ,struct mlx4_icm*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlx4_MAP_ICM(struct mlx4_dev *dev, struct mlx4_icm *icm, u64 virt)
{
	return mlx4_map_cmd(dev, MLX4_CMD_MAP_ICM, icm, virt);
}