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
struct amdgpu_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ amdgpu_debugfs_fence_init (struct amdgpu_device*) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 

int amdgpu_fence_driver_init(struct amdgpu_device *adev)
{
	if (amdgpu_debugfs_fence_init(adev))
		dev_err(adev->dev, "fence debugfs file creation failed\n");

	return 0;
}