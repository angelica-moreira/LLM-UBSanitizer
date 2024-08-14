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

/* Variables and functions */
 int /*<<< orphan*/  RTD_CLOCK_BASE ; 
 int rtd_ns_to_timer_base (unsigned int*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rtd_ns_to_timer(unsigned int *ns, unsigned int flags)
{
	return rtd_ns_to_timer_base(ns, flags, RTD_CLOCK_BASE);
}