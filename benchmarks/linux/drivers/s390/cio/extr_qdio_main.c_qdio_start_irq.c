#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  queue_irq_state; } ;
struct TYPE_6__ {TYPE_2__ in; } ;
struct qdio_q {TYPE_3__ u; int /*<<< orphan*/  first_to_check; } ;
struct qdio_irq {struct qdio_q** input_qs; } ;
struct ccw_device {TYPE_1__* private; } ;
struct TYPE_4__ {struct qdio_irq* qdio_data; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  QDIO_QUEUE_IRQS_DISABLED ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clear_nonshared_ind (struct qdio_irq*) ; 
 int /*<<< orphan*/  qdio_inbound_q_done (struct qdio_q*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qdio_stop_polling (struct qdio_q*) ; 
 scalar_t__ test_and_set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ test_nonshared_ind (struct qdio_irq*) ; 

int qdio_start_irq(struct ccw_device *cdev, int nr)
{
	struct qdio_q *q;
	struct qdio_irq *irq_ptr = cdev->private->qdio_data;

	if (!irq_ptr)
		return -ENODEV;
	q = irq_ptr->input_qs[nr];

	clear_nonshared_ind(irq_ptr);
	qdio_stop_polling(q);
	clear_bit(QDIO_QUEUE_IRQS_DISABLED, &q->u.in.queue_irq_state);

	/*
	 * We need to check again to not lose initiative after
	 * resetting the ACK state.
	 */
	if (test_nonshared_ind(irq_ptr))
		goto rescan;
	if (!qdio_inbound_q_done(q, q->first_to_check))
		goto rescan;
	return 0;

rescan:
	if (test_and_set_bit(QDIO_QUEUE_IRQS_DISABLED,
			     &q->u.in.queue_irq_state))
		return 0;
	else
		return 1;

}