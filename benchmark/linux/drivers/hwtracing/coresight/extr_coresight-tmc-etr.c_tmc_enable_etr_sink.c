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
typedef  int u32 ;
struct coresight_device {int dummy; } ;

/* Variables and functions */
#define  CS_MODE_PERF 129 
#define  CS_MODE_SYSFS 128 
 int EINVAL ; 
 int tmc_enable_etr_sink_perf (struct coresight_device*,void*) ; 
 int tmc_enable_etr_sink_sysfs (struct coresight_device*) ; 

__attribute__((used)) static int tmc_enable_etr_sink(struct coresight_device *csdev,
			       u32 mode, void *data)
{
	switch (mode) {
	case CS_MODE_SYSFS:
		return tmc_enable_etr_sink_sysfs(csdev);
	case CS_MODE_PERF:
		return tmc_enable_etr_sink_perf(csdev, data);
	}

	/* We shouldn't be here */
	return -EINVAL;
}