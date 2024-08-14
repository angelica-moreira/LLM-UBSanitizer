#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ dl_nr_running; } ;
struct rq {TYPE_1__ dl; } ;

/* Variables and functions */

__attribute__((used)) static inline bool sched_dl_runnable(struct rq *rq)
{
	return rq->dl.dl_nr_running > 0;
}