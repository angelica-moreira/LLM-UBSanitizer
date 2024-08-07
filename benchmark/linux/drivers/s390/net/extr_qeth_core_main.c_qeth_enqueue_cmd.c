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
struct qeth_cmd_buffer {int /*<<< orphan*/  list; } ;
struct qeth_card {int /*<<< orphan*/  lock; int /*<<< orphan*/  cmd_waiter_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void qeth_enqueue_cmd(struct qeth_card *card,
			     struct qeth_cmd_buffer *iob)
{
	spin_lock_irq(&card->lock);
	list_add_tail(&iob->list, &card->cmd_waiter_list);
	spin_unlock_irq(&card->lock);
}