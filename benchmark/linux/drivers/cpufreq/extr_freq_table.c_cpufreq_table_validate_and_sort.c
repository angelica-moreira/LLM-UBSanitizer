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
struct cpufreq_policy {int /*<<< orphan*/  freq_table; } ;

/* Variables and functions */
 int cpufreq_frequency_table_cpuinfo (struct cpufreq_policy*,int /*<<< orphan*/ ) ; 
 int set_freq_table_sorted (struct cpufreq_policy*) ; 

int cpufreq_table_validate_and_sort(struct cpufreq_policy *policy)
{
	int ret;

	if (!policy->freq_table)
		return 0;

	ret = cpufreq_frequency_table_cpuinfo(policy, policy->freq_table);
	if (ret)
		return ret;

	return set_freq_table_sorted(policy);
}