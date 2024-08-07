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
struct mlx5_events {TYPE_2__* notifiers; } ;
struct TYPE_3__ {struct mlx5_events* events; } ;
struct mlx5_core_dev {TYPE_1__ priv; } ;
struct TYPE_4__ {int /*<<< orphan*/  nb; struct mlx5_events* ctx; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * events_nbs_ref ; 
 int /*<<< orphan*/  mlx5_eq_notifier_register (struct mlx5_core_dev*,int /*<<< orphan*/ *) ; 

void mlx5_events_start(struct mlx5_core_dev *dev)
{
	struct mlx5_events *events = dev->priv.events;
	int i;

	for (i = 0; i < ARRAY_SIZE(events_nbs_ref); i++) {
		events->notifiers[i].nb  = events_nbs_ref[i];
		events->notifiers[i].ctx = events;
		mlx5_eq_notifier_register(dev, &events->notifiers[i].nb);
	}
}