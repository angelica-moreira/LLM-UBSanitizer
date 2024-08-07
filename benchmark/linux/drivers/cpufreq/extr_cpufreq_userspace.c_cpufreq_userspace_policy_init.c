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
struct cpufreq_policy {unsigned int* governor_data; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int cpufreq_userspace_policy_init(struct cpufreq_policy *policy)
{
	unsigned int *setspeed;

	setspeed = kzalloc(sizeof(*setspeed), GFP_KERNEL);
	if (!setspeed)
		return -ENOMEM;

	policy->governor_data = setspeed;
	return 0;
}