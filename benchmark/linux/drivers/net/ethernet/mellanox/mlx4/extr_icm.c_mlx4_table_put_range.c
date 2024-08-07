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
typedef  scalar_t__ u32 ;
struct mlx4_icm_table {int obj_size; } ;
struct mlx4_dev {int dummy; } ;

/* Variables and functions */
 int MLX4_TABLE_CHUNK_SIZE ; 
 int /*<<< orphan*/  mlx4_table_put (struct mlx4_dev*,struct mlx4_icm_table*,scalar_t__) ; 

void mlx4_table_put_range(struct mlx4_dev *dev, struct mlx4_icm_table *table,
			  u32 start, u32 end)
{
	u32 i;

	for (i = start; i <= end; i += MLX4_TABLE_CHUNK_SIZE / table->obj_size)
		mlx4_table_put(dev, table, i);
}