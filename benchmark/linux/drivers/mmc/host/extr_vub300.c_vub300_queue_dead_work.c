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
struct vub300_mmc_host {int /*<<< orphan*/  kref; int /*<<< orphan*/  deadwork; } ;

/* Variables and functions */
 int /*<<< orphan*/  deadworkqueue ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vub300_delete ; 

__attribute__((used)) static void vub300_queue_dead_work(struct vub300_mmc_host *vub300)
{
	kref_get(&vub300->kref);
	if (queue_work(deadworkqueue, &vub300->deadwork)) {
		/*
		 * then the deadworkqueue was not previously
		 * running and the above get ref is obvious
		 * required and will be put when the thread
		 * terminates by a specific call
		 */
	} else {
		/*
		 * the deadworkqueue was already running from
		 * a previous invocation and thus to keep the
		 * kref counts correct we must undo the get
		 */
		kref_put(&vub300->kref, vub300_delete);
	}
}