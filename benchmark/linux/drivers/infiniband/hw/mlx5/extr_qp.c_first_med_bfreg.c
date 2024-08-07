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
 int ENOMEM ; 
 scalar_t__ num_med_bfreg (struct mlx5_ib_dev*,struct mlx5_bfreg_info*) ; 

__attribute__((used)) static int first_med_bfreg(struct mlx5_ib_dev *dev,
			   struct mlx5_bfreg_info *bfregi)
{
	return num_med_bfreg(dev, bfregi) ? 1 : -ENOMEM;
}