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
struct qlcnic_mailbox {int /*<<< orphan*/  work_q; } ;

/* Variables and functions */
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct qlcnic_mailbox*) ; 

void qlcnic_83xx_free_mailbox(struct qlcnic_mailbox *mbx)
{
	if (!mbx)
		return;

	destroy_workqueue(mbx->work_q);
	kfree(mbx);
}