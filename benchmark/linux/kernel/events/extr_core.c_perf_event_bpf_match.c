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
struct TYPE_2__ {int bpf_event; } ;
struct perf_event {TYPE_1__ attr; } ;

/* Variables and functions */

__attribute__((used)) static int perf_event_bpf_match(struct perf_event *event)
{
	return event->attr.bpf_event;
}