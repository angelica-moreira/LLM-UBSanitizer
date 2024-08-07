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
struct perf_event {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  hw_perf_event_destroy (struct perf_event*) ; 
 int /*<<< orphan*/  x86_del_exclusive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  x86_lbr_exclusive_lbr ; 

void hw_perf_lbr_event_destroy(struct perf_event *event)
{
	hw_perf_event_destroy(event);

	/* undo the lbr/bts event accounting */
	x86_del_exclusive(x86_lbr_exclusive_lbr);
}