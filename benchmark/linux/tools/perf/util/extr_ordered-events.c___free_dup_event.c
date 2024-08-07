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
struct TYPE_2__ {scalar_t__ size; } ;
union perf_event {TYPE_1__ header; } ;
struct ordered_events {int /*<<< orphan*/  cur_alloc_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (union perf_event*) ; 

__attribute__((used)) static void __free_dup_event(struct ordered_events *oe, union perf_event *event)
{
	if (event) {
		oe->cur_alloc_size -= event->header.size;
		free(event);
	}
}