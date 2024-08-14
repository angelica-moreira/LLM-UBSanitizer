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
 int /*<<< orphan*/  GPU_CMD ; 
 int /*<<< orphan*/  GPU_CMD_CLEAN_CACHES ; 
 int /*<<< orphan*/  gpu_write (struct panfrost_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void panfrost_perfcnt_sample_done(struct panfrost_device *pfdev)
{
	gpu_write(pfdev, GPU_CMD, GPU_CMD_CLEAN_CACHES);
}