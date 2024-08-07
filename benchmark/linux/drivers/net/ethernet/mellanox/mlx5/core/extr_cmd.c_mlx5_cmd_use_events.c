#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  nb; } ;
struct mlx5_core_dev {TYPE_1__ cmd; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD ; 
 int /*<<< orphan*/  CMD_MODE_EVENTS ; 
 int /*<<< orphan*/  MLX5_NB_INIT (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cmd_comp_notifier ; 
 int /*<<< orphan*/  mlx5_cmd_change_mod (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5_eq_notifier_register (struct mlx5_core_dev*,int /*<<< orphan*/ *) ; 

void mlx5_cmd_use_events(struct mlx5_core_dev *dev)
{
	MLX5_NB_INIT(&dev->cmd.nb, cmd_comp_notifier, CMD);
	mlx5_eq_notifier_register(dev, &dev->cmd.nb);
	mlx5_cmd_change_mod(dev, CMD_MODE_EVENTS);
}