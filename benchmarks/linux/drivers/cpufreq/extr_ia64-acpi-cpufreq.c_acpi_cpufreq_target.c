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
struct cpufreq_policy {int /*<<< orphan*/  cpu; } ;
struct cpufreq_acpi_req {unsigned int state; int /*<<< orphan*/  cpu; } ;

/* Variables and functions */
 int /*<<< orphan*/  processor_set_freq ; 
 int work_on_cpu (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct cpufreq_acpi_req*) ; 

__attribute__((used)) static int
acpi_cpufreq_target (
	struct cpufreq_policy   *policy,
	unsigned int index)
{
	struct cpufreq_acpi_req req;

	req.cpu = policy->cpu;
	req.state = index;

	return work_on_cpu(req.cpu, processor_set_freq, &req);
}