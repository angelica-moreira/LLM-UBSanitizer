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
struct mlx5_devcom_component {int /*<<< orphan*/  sem; } ;
struct mlx5_devcom {TYPE_1__* priv; } ;
typedef  enum mlx5_devcom_components { ____Placeholder_mlx5_devcom_components } mlx5_devcom_components ;
struct TYPE_2__ {struct mlx5_devcom_component* components; } ;

/* Variables and functions */
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

void mlx5_devcom_release_peer_data(struct mlx5_devcom *devcom,
				   enum mlx5_devcom_components id)
{
	struct mlx5_devcom_component *comp = &devcom->priv->components[id];

	up_read(&comp->sem);
}