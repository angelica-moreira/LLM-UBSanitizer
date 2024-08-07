#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {TYPE_3__* eq_table; } ;
struct mlx5_core_dev {TYPE_4__ priv; } ;
struct TYPE_5__ {int /*<<< orphan*/  irqn; } ;
struct TYPE_6__ {TYPE_1__ core; } ;
struct TYPE_7__ {TYPE_2__ async_eq; } ;

/* Variables and functions */
 int /*<<< orphan*/  synchronize_irq (int /*<<< orphan*/ ) ; 

void mlx5_eq_synchronize_async_irq(struct mlx5_core_dev *dev)
{
	synchronize_irq(dev->priv.eq_table->async_eq.core.irqn);
}