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
struct dyn_event {int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  trace_kprobe_ops ; 

__attribute__((used)) static bool is_trace_kprobe(struct dyn_event *ev)
{
	return ev->ops == &trace_kprobe_ops;
}