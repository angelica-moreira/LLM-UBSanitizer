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
struct mlx5e_cq {int /*<<< orphan*/  wq_ctrl; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5_wq_destroy (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mlx5e_free_cq(struct mlx5e_cq *cq)
{
	mlx5_wq_destroy(&cq->wq_ctrl);
}