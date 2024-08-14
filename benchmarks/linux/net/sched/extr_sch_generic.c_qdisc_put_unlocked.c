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
struct Qdisc {int flags; int /*<<< orphan*/  refcnt; } ;

/* Variables and functions */
 int TCQ_F_BUILTIN ; 
 int /*<<< orphan*/  qdisc_destroy (struct Qdisc*) ; 
 int /*<<< orphan*/  refcount_dec_and_rtnl_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rtnl_unlock () ; 

void qdisc_put_unlocked(struct Qdisc *qdisc)
{
	if (qdisc->flags & TCQ_F_BUILTIN ||
	    !refcount_dec_and_rtnl_lock(&qdisc->refcnt))
		return;

	qdisc_destroy(qdisc);
	rtnl_unlock();
}