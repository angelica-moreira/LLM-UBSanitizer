#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ionic_queue {int num_descs; TYPE_2__* head; TYPE_1__* tail; } ;
struct TYPE_4__ {unsigned int index; } ;
struct TYPE_3__ {unsigned int index; } ;

/* Variables and functions */

__attribute__((used)) static bool ionic_q_is_posted(struct ionic_queue *q, unsigned int pos)
{
	unsigned int mask, tail, head;

	mask = q->num_descs - 1;
	tail = q->tail->index;
	head = q->head->index;

	return ((pos - tail) & mask) < ((head - tail) & mask);
}