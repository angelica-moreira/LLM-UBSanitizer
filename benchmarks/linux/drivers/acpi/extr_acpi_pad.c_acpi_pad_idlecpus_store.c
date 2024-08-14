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
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 int /*<<< orphan*/  acpi_pad_idle_cpus (unsigned long) ; 
 int /*<<< orphan*/  isolated_cpus_lock ; 
 scalar_t__ kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t acpi_pad_idlecpus_store(struct device *dev,
	struct device_attribute *attr, const char *buf, size_t count)
{
	unsigned long num;
	if (kstrtoul(buf, 0, &num))
		return -EINVAL;
	mutex_lock(&isolated_cpus_lock);
	acpi_pad_idle_cpus(num);
	mutex_unlock(&isolated_cpus_lock);
	return count;
}