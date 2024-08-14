#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/ * irq_handler_t ;
struct TYPE_5__ {int /*<<< orphan*/ * user_data; int /*<<< orphan*/ * user_handler; int /*<<< orphan*/  irq; TYPE_1__* pdev; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int devm_request_irq (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,TYPE_2__*) ; 
 TYPE_2__ dispc ; 
 int /*<<< orphan*/  dispc_irq_handler ; 
 int /*<<< orphan*/  smp_wmb () ; 

int dispc_request_irq(irq_handler_t handler, void *dev_id)
{
	int r;

	if (dispc.user_handler != NULL)
		return -EBUSY;

	dispc.user_handler = handler;
	dispc.user_data = dev_id;

	/* ensure the dispc_irq_handler sees the values above */
	smp_wmb();

	r = devm_request_irq(&dispc.pdev->dev, dispc.irq, dispc_irq_handler,
			     IRQF_SHARED, "OMAP DISPC", &dispc);
	if (r) {
		dispc.user_handler = NULL;
		dispc.user_data = NULL;
	}

	return r;
}