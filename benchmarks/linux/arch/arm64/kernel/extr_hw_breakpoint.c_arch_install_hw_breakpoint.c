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
 int /*<<< orphan*/  HW_BREAKPOINT_INSTALL ; 
 int hw_breakpoint_control (struct perf_event*,int /*<<< orphan*/ ) ; 

int arch_install_hw_breakpoint(struct perf_event *bp)
{
	return hw_breakpoint_control(bp, HW_BREAKPOINT_INSTALL);
}