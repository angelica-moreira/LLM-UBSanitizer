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
struct qeth_qdio_out_q {int /*<<< orphan*/  qdio_bufs; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  QDIO_MAX_BUFFERS_PER_Q ; 
 int /*<<< orphan*/  kfree (struct qeth_qdio_out_q*) ; 
 struct qeth_qdio_out_q* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ qdio_alloc_buffers (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct qeth_qdio_out_q *qeth_alloc_output_queue(void)
{
	struct qeth_qdio_out_q *q = kzalloc(sizeof(*q), GFP_KERNEL);

	if (!q)
		return NULL;

	if (qdio_alloc_buffers(q->qdio_bufs, QDIO_MAX_BUFFERS_PER_Q)) {
		kfree(q);
		return NULL;
	}
	return q;
}