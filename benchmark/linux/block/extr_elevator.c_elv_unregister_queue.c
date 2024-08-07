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
struct request_queue {struct elevator_queue* elevator; } ;
struct elevator_queue {scalar_t__ registered; int /*<<< orphan*/  kobj; } ;

/* Variables and functions */
 int /*<<< orphan*/  KOBJ_REMOVE ; 
 int /*<<< orphan*/  kobject_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kobject_uevent (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wbt_enable_default (struct request_queue*) ; 

void elv_unregister_queue(struct request_queue *q)
{
	if (q) {
		struct elevator_queue *e = q->elevator;

		kobject_uevent(&e->kobj, KOBJ_REMOVE);
		kobject_del(&e->kobj);

		e->registered = 0;
		/* Re-enable throttling in case elevator disabled it */
		wbt_enable_default(q);
	}
}