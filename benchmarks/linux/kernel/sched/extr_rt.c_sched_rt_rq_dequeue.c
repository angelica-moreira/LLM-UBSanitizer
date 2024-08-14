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
struct rt_rq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dequeue_top_rt_rq (struct rt_rq*) ; 

__attribute__((used)) static inline void sched_rt_rq_dequeue(struct rt_rq *rt_rq)
{
	dequeue_top_rt_rq(rt_rq);
}