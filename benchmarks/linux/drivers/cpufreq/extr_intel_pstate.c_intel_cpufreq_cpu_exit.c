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
struct freq_qos_request {int dummy; } ;
struct cpufreq_policy {struct freq_qos_request* driver_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  freq_qos_remove_request (struct freq_qos_request*) ; 
 int intel_pstate_cpu_exit (struct cpufreq_policy*) ; 
 int /*<<< orphan*/  kfree (struct freq_qos_request*) ; 

__attribute__((used)) static int intel_cpufreq_cpu_exit(struct cpufreq_policy *policy)
{
	struct freq_qos_request *req;

	req = policy->driver_data;

	freq_qos_remove_request(req + 1);
	freq_qos_remove_request(req);
	kfree(req);

	return intel_pstate_cpu_exit(policy);
}