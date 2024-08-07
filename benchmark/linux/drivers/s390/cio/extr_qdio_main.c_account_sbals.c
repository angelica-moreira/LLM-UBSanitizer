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
struct TYPE_2__ {unsigned int nr_sbal_total; int /*<<< orphan*/ * nr_sbals; } ;
struct qdio_q {TYPE_1__ q_stats; } ;

/* Variables and functions */
 unsigned int QDIO_MAX_BUFFERS_MASK ; 
 int ilog2 (unsigned int) ; 

__attribute__((used)) static inline void account_sbals(struct qdio_q *q, unsigned int count)
{
	int pos;

	q->q_stats.nr_sbal_total += count;
	if (count == QDIO_MAX_BUFFERS_MASK) {
		q->q_stats.nr_sbals[7]++;
		return;
	}
	pos = ilog2(count);
	q->q_stats.nr_sbals[pos]++;
}