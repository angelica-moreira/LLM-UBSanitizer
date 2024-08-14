#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct mlx5_devcom_component {int /*<<< orphan*/  sem; TYPE_1__* device; int /*<<< orphan*/  handler; } ;
struct mlx5_devcom {size_t idx; TYPE_2__* priv; } ;
typedef  int /*<<< orphan*/  mlx5_devcom_event_handler_t ;
typedef  enum mlx5_devcom_components { ____Placeholder_mlx5_devcom_components } mlx5_devcom_components ;
struct TYPE_4__ {struct mlx5_devcom_component* components; } ;
struct TYPE_3__ {void* data; } ;

/* Variables and functions */
 scalar_t__ IS_ERR_OR_NULL (struct mlx5_devcom*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

void mlx5_devcom_register_component(struct mlx5_devcom *devcom,
				    enum mlx5_devcom_components id,
				    mlx5_devcom_event_handler_t handler,
				    void *data)
{
	struct mlx5_devcom_component *comp;

	if (IS_ERR_OR_NULL(devcom))
		return;

	WARN_ON(!data);

	comp = &devcom->priv->components[id];
	down_write(&comp->sem);
	comp->handler = handler;
	comp->device[devcom->idx].data = data;
	up_write(&comp->sem);
}