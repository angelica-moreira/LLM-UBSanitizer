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
struct netdev_queue {struct Qdisc* qdisc_sleeping; int /*<<< orphan*/  qdisc; } ;
struct net_device {int dummy; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ ,struct Qdisc*) ; 

__attribute__((used)) static void dev_init_scheduler_queue(struct net_device *dev,
				     struct netdev_queue *dev_queue,
				     void *_qdisc)
{
	struct Qdisc *qdisc = _qdisc;

	rcu_assign_pointer(dev_queue->qdisc, qdisc);
	dev_queue->qdisc_sleeping = qdisc;
}