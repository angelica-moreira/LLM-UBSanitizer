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
struct mlx5_fc {int /*<<< orphan*/  id; } ;
struct mlx5_core_dev {int dummy; } ;

/* Variables and functions */
 int mlx5_cmd_fc_query (struct mlx5_core_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int mlx5_fc_query(struct mlx5_core_dev *dev, struct mlx5_fc *counter,
		  u64 *packets, u64 *bytes)
{
	return mlx5_cmd_fc_query(dev, counter->id, packets, bytes);
}