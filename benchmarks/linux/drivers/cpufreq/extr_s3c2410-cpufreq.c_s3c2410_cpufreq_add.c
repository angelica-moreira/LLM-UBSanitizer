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
struct subsys_interface {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  s3c2410_cpufreq_info ; 
 int s3c_cpufreq_register (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int s3c2410_cpufreq_add(struct device *dev,
			       struct subsys_interface *sif)
{
	return s3c_cpufreq_register(&s3c2410_cpufreq_info);
}