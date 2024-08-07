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
struct spi_controller {int running; int /*<<< orphan*/  pump_messages; int /*<<< orphan*/  kworker; int /*<<< orphan*/  queue_lock; int /*<<< orphan*/ * cur_msg; scalar_t__ busy; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  kthread_queue_work (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int spi_start_queue(struct spi_controller *ctlr)
{
	unsigned long flags;

	spin_lock_irqsave(&ctlr->queue_lock, flags);

	if (ctlr->running || ctlr->busy) {
		spin_unlock_irqrestore(&ctlr->queue_lock, flags);
		return -EBUSY;
	}

	ctlr->running = true;
	ctlr->cur_msg = NULL;
	spin_unlock_irqrestore(&ctlr->queue_lock, flags);

	kthread_queue_work(&ctlr->kworker, &ctlr->pump_messages);

	return 0;
}