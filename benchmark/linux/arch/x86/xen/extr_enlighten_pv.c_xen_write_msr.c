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
 int /*<<< orphan*/  xen_write_msr_safe (unsigned int,unsigned int,unsigned int) ; 

__attribute__((used)) static void xen_write_msr(unsigned int msr, unsigned low, unsigned high)
{
	/*
	 * This will silently swallow a #GP from WRMSR.  It may be worth
	 * changing that.
	 */
	xen_write_msr_safe(msr, low, high);
}