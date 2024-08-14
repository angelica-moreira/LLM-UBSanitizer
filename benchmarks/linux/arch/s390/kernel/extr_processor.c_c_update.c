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
typedef  scalar_t__ loff_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_online_mask ; 
 scalar_t__ cpumask_next (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ nr_cpu_ids ; 

__attribute__((used)) static inline void *c_update(loff_t *pos)
{
	if (*pos)
		*pos = cpumask_next(*pos - 1, cpu_online_mask);
	return *pos < nr_cpu_ids ? (void *)*pos + 1 : NULL;
}