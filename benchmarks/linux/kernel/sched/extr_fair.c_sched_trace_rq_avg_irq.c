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
struct sched_avg {int dummy; } ;
struct rq {struct sched_avg const avg_irq; } ;

/* Variables and functions */

const struct sched_avg *sched_trace_rq_avg_irq(struct rq *rq)
{
#if defined(CONFIG_SMP) && defined(CONFIG_HAVE_SCHED_AVG_IRQ)
	return rq ? &rq->avg_irq : NULL;
#else
	return NULL;
#endif
}