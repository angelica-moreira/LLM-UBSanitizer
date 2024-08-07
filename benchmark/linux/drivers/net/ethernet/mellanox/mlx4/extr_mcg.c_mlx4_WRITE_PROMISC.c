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
typedef  int u8 ;
typedef  int u32 ;
struct mlx4_dev {int dummy; } ;
struct mlx4_cmd_mailbox {int /*<<< orphan*/  dma; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLX4_CMD_NATIVE ; 
 int /*<<< orphan*/  MLX4_CMD_TIME_CLASS_A ; 
 int /*<<< orphan*/  MLX4_CMD_WRITE_MCG ; 
 int mlx4_cmd (struct mlx4_dev*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mlx4_WRITE_PROMISC(struct mlx4_dev *dev, u8 port, u8 steer,
			      struct mlx4_cmd_mailbox *mailbox)
{
	u32 in_mod;

	in_mod = (u32) port << 16 | steer << 1;
	return mlx4_cmd(dev, mailbox->dma, in_mod, 0x1,
			MLX4_CMD_WRITE_MCG, MLX4_CMD_TIME_CLASS_A,
			MLX4_CMD_NATIVE);
}