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
 scalar_t__ __USE_RTC () ; 
 unsigned long get_rtcl () ; 
 unsigned long get_tbl () ; 
 int /*<<< orphan*/  spin_begin () ; 
 int /*<<< orphan*/  spin_cpu_relax () ; 
 int /*<<< orphan*/  spin_end () ; 
 scalar_t__ tb_invalid ; 

void __delay(unsigned long loops)
{
	unsigned long start;
	int diff;

	spin_begin();
	if (__USE_RTC()) {
		start = get_rtcl();
		do {
			/* the RTCL register wraps at 1000000000 */
			diff = get_rtcl() - start;
			if (diff < 0)
				diff += 1000000000;
			spin_cpu_relax();
		} while (diff < loops);
	} else if (tb_invalid) {
		/*
		 * TB is in error state and isn't ticking anymore.
		 * HMI handler was unable to recover from TB error.
		 * Return immediately, so that kernel won't get stuck here.
		 */
		spin_cpu_relax();
	} else {
		start = get_tbl();
		while (get_tbl() - start < loops)
			spin_cpu_relax();
	}
	spin_end();
}