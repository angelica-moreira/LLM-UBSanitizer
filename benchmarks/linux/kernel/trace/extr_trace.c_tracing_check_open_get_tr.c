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
struct trace_array {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  LOCKDOWN_TRACEFS ; 
 int security_locked_down (int /*<<< orphan*/ ) ; 
 scalar_t__ trace_array_get (struct trace_array*) ; 
 scalar_t__ tracing_disabled ; 

int tracing_check_open_get_tr(struct trace_array *tr)
{
	int ret;

	ret = security_locked_down(LOCKDOWN_TRACEFS);
	if (ret)
		return ret;

	if (tracing_disabled)
		return -ENODEV;

	if (tr && trace_array_get(tr) < 0)
		return -ENODEV;

	return 0;
}