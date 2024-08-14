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
struct ib_umem_odp {int /*<<< orphan*/  umem_mutex; int /*<<< orphan*/  notifier_completion; int /*<<< orphan*/  notifiers_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ib_umem_notifier_start_account(struct ib_umem_odp *umem_odp)
{
	mutex_lock(&umem_odp->umem_mutex);
	if (umem_odp->notifiers_count++ == 0)
		/*
		 * Initialize the completion object for waiting on
		 * notifiers. Since notifier_count is zero, no one should be
		 * waiting right now.
		 */
		reinit_completion(&umem_odp->notifier_completion);
	mutex_unlock(&umem_odp->umem_mutex);
}