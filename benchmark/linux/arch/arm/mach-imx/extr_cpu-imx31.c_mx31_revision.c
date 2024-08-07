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
 int mx31_cpu_rev ; 
 int mx31_read_cpu_rev () ; 

int mx31_revision(void)
{
	if (mx31_cpu_rev == -1)
		mx31_cpu_rev = mx31_read_cpu_rev();

	return mx31_cpu_rev;
}