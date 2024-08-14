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
struct cpufreq_policy {int dummy; } ;

/* Variables and functions */
 unsigned int cpufreq_verify_current_freq (struct cpufreq_policy*,int) ; 
 int /*<<< orphan*/  policy_is_inactive (struct cpufreq_policy*) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int __cpufreq_get(struct cpufreq_policy *policy)
{
	if (unlikely(policy_is_inactive(policy)))
		return 0;

	return cpufreq_verify_current_freq(policy, true);
}