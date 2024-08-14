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
struct task_struct {int dummy; } ;
struct rq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sub_nr_running (struct rq*,int) ; 

__attribute__((used)) static void
dequeue_task_stop(struct rq *rq, struct task_struct *p, int flags)
{
	sub_nr_running(rq, 1);
}