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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpumap_print_to_pagebuf (int,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pmu_cpu ; 

__attribute__((used)) static ssize_t l2x0_pmu_cpumask_show(struct device *dev,
				     struct device_attribute *attr, char *buf)
{
	return cpumap_print_to_pagebuf(true, buf, &pmu_cpu);
}