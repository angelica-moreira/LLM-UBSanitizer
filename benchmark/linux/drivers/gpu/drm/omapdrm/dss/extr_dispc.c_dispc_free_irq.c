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
struct dispc_device {int /*<<< orphan*/ * user_data; int /*<<< orphan*/ * user_handler; int /*<<< orphan*/  irq; TYPE_1__* pdev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  devm_free_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct dispc_device*) ; 

__attribute__((used)) static void dispc_free_irq(struct dispc_device *dispc, void *dev_id)
{
	devm_free_irq(&dispc->pdev->dev, dispc->irq, dispc);

	dispc->user_handler = NULL;
	dispc->user_data = NULL;
}