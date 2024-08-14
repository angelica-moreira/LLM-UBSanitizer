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
struct cpu_hw_events {int is_fake; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENOMEM ; 
 struct cpu_hw_events* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  free_fake_cpuc (struct cpu_hw_events*) ; 
 scalar_t__ intel_cpuc_prepare (struct cpu_hw_events*,int) ; 
 struct cpu_hw_events* kzalloc (int,int /*<<< orphan*/ ) ; 
 int raw_smp_processor_id () ; 

__attribute__((used)) static struct cpu_hw_events *allocate_fake_cpuc(void)
{
	struct cpu_hw_events *cpuc;
	int cpu = raw_smp_processor_id();

	cpuc = kzalloc(sizeof(*cpuc), GFP_KERNEL);
	if (!cpuc)
		return ERR_PTR(-ENOMEM);
	cpuc->is_fake = 1;

	if (intel_cpuc_prepare(cpuc, cpu))
		goto error;

	return cpuc;
error:
	free_fake_cpuc(cpuc);
	return ERR_PTR(-ENOMEM);
}