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
 int /*<<< orphan*/  __oprofile_hrtimer_start ; 
 int ctr_running ; 
 int /*<<< orphan*/  get_online_cpus () ; 
 int /*<<< orphan*/  on_each_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  put_online_cpus () ; 

__attribute__((used)) static int oprofile_hrtimer_start(void)
{
	get_online_cpus();
	ctr_running = 1;
	on_each_cpu(__oprofile_hrtimer_start, NULL, 1);
	put_online_cpus();
	return 0;
}