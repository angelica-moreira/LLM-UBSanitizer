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
struct data_queue {scalar_t__ qid; TYPE_3__* rt2x00dev; } ;
struct TYPE_6__ {TYPE_2__* ops; } ;
struct TYPE_5__ {TYPE_1__* lib; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* flush_queue ) (struct data_queue*,int) ;int /*<<< orphan*/  (* kick_queue ) (struct data_queue*) ;} ;

/* Variables and functions */
 scalar_t__ QID_AC_BE ; 
 scalar_t__ QID_AC_BK ; 
 scalar_t__ QID_AC_VI ; 
 scalar_t__ QID_AC_VO ; 
 scalar_t__ likely (int /*<<< orphan*/  (*) (struct data_queue*,int)) ; 
 int /*<<< orphan*/  rt2x00_warn (TYPE_3__*,char*,scalar_t__) ; 
 scalar_t__ rt2x00queue_empty (struct data_queue*) ; 
 int /*<<< orphan*/  stub1 (struct data_queue*) ; 
 int /*<<< orphan*/  stub2 (struct data_queue*,int) ; 
 scalar_t__ unlikely (int) ; 

void rt2x00queue_flush_queue(struct data_queue *queue, bool drop)
{
	bool tx_queue =
		(queue->qid == QID_AC_VO) ||
		(queue->qid == QID_AC_VI) ||
		(queue->qid == QID_AC_BE) ||
		(queue->qid == QID_AC_BK);

	if (rt2x00queue_empty(queue))
		return;

	/*
	 * If we are not supposed to drop any pending
	 * frames, this means we must force a start (=kick)
	 * to the queue to make sure the hardware will
	 * start transmitting.
	 */
	if (!drop && tx_queue)
		queue->rt2x00dev->ops->lib->kick_queue(queue);

	/*
	 * Check if driver supports flushing, if that is the case we can
	 * defer the flushing to the driver. Otherwise we must use the
	 * alternative which just waits for the queue to become empty.
	 */
	if (likely(queue->rt2x00dev->ops->lib->flush_queue))
		queue->rt2x00dev->ops->lib->flush_queue(queue, drop);

	/*
	 * The queue flush has failed...
	 */
	if (unlikely(!rt2x00queue_empty(queue)))
		rt2x00_warn(queue->rt2x00dev, "Queue %d failed to flush\n",
			    queue->qid);
}