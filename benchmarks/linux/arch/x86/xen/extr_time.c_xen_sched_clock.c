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
typedef  scalar_t__ u64 ;

/* Variables and functions */
 scalar_t__ xen_clocksource_read () ; 
 scalar_t__ xen_sched_clock_offset ; 

__attribute__((used)) static u64 xen_sched_clock(void)
{
	return xen_clocksource_read() - xen_sched_clock_offset;
}