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
 int EINVAL ; 
 scalar_t__ RUNTIME_INF ; 
 scalar_t__ sysctl_sched_rt_period ; 
 scalar_t__ sysctl_sched_rt_runtime ; 

__attribute__((used)) static int sched_rt_global_validate(void)
{
	if (sysctl_sched_rt_period <= 0)
		return -EINVAL;

	if ((sysctl_sched_rt_runtime != RUNTIME_INF) &&
		(sysctl_sched_rt_runtime > sysctl_sched_rt_period))
		return -EINVAL;

	return 0;
}