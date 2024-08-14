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
struct kthread_delayed_work {int /*<<< orphan*/  work; } ;

/* Variables and functions */
 int __kthread_cancel_work_sync (int /*<<< orphan*/ *,int) ; 

bool kthread_cancel_delayed_work_sync(struct kthread_delayed_work *dwork)
{
	return __kthread_cancel_work_sync(&dwork->work, true);
}