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
struct mlx5_hv_vhca_agent {void* priv; } ;

/* Variables and functions */

void *mlx5_hv_vhca_agent_priv(struct mlx5_hv_vhca_agent *agent)
{
	return agent->priv;
}