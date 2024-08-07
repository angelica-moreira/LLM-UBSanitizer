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
struct rq_wait {int /*<<< orphan*/  inflight; } ;

/* Variables and functions */
 int atomic_inc_below (int /*<<< orphan*/ *,unsigned int) ; 

bool rq_wait_inc_below(struct rq_wait *rq_wait, unsigned int limit)
{
	return atomic_inc_below(&rq_wait->inflight, limit);
}