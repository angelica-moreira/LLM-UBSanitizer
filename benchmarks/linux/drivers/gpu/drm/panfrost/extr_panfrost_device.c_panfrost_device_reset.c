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
struct panfrost_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  panfrost_gpu_power_on (struct panfrost_device*) ; 
 int /*<<< orphan*/  panfrost_gpu_soft_reset (struct panfrost_device*) ; 
 int /*<<< orphan*/  panfrost_job_enable_interrupts (struct panfrost_device*) ; 
 int /*<<< orphan*/  panfrost_mmu_reset (struct panfrost_device*) ; 

void panfrost_device_reset(struct panfrost_device *pfdev)
{
	panfrost_gpu_soft_reset(pfdev);

	panfrost_gpu_power_on(pfdev);
	panfrost_mmu_reset(pfdev);
	panfrost_job_enable_interrupts(pfdev);
}