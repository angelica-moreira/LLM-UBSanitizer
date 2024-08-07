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
struct ring_buffer_event {int dummy; } ;
struct ring_buffer {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __buffer_unlock_commit (struct ring_buffer*,struct ring_buffer_event*) ; 

void
trace_buffer_unlock_commit_nostack(struct ring_buffer *buffer,
				   struct ring_buffer_event *event)
{
	__buffer_unlock_commit(buffer, event);
}