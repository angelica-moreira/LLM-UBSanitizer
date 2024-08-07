#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct xgene_pmu_dev {TYPE_1__* parent; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int /*<<< orphan*/  cpu; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpumap_print_to_pagebuf (int,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_get_drvdata (struct device*) ; 
 struct xgene_pmu_dev* to_pmu_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t xgene_pmu_cpumask_show(struct device *dev,
				      struct device_attribute *attr, char *buf)
{
	struct xgene_pmu_dev *pmu_dev = to_pmu_dev(dev_get_drvdata(dev));

	return cpumap_print_to_pagebuf(true, buf, &pmu_dev->parent->cpu);
}