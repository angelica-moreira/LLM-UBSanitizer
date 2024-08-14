#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct TYPE_5__* q_next; } ;
typedef  TYPE_1__ ips_scb_t ;
struct TYPE_6__ {int /*<<< orphan*/  count; TYPE_1__* tail; TYPE_1__* head; } ;
typedef  TYPE_2__ ips_scb_queue_t ;

/* Variables and functions */
 int /*<<< orphan*/  METHOD_TRACE (char*,int) ; 

__attribute__((used)) static void
ips_putq_scb_head(ips_scb_queue_t * queue, ips_scb_t * item)
{
	METHOD_TRACE("ips_putq_scb_head", 1);

	if (!item)
		return;

	item->q_next = queue->head;
	queue->head = item;

	if (!queue->tail)
		queue->tail = item;

	queue->count++;
}