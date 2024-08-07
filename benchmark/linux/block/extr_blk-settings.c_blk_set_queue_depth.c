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
struct request_queue {unsigned int queue_depth; } ;

/* Variables and functions */
 int /*<<< orphan*/  rq_qos_queue_depth_changed (struct request_queue*) ; 

void blk_set_queue_depth(struct request_queue *q, unsigned int depth)
{
	q->queue_depth = depth;
	rq_qos_queue_depth_changed(q);
}