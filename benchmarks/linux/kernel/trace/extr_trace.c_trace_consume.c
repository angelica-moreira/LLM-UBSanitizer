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
struct trace_iterator {int /*<<< orphan*/  lost_events; int /*<<< orphan*/  ts; int /*<<< orphan*/  cpu; TYPE_1__* trace_buffer; } ;
struct TYPE_2__ {int /*<<< orphan*/  buffer; } ;

/* Variables and functions */
 int /*<<< orphan*/  ring_buffer_consume (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void trace_consume(struct trace_iterator *iter)
{
	ring_buffer_consume(iter->trace_buffer->buffer, iter->cpu, &iter->ts,
			    &iter->lost_events);
}