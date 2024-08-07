#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  union acpi_object {int dummy; } acpi_object ;
struct TYPE_4__ {int /*<<< orphan*/  pcie_dev_rdy; } ;
struct amdgpu_atcs {TYPE_2__ functions; } ;
struct amdgpu_device {TYPE_1__* pdev; struct amdgpu_atcs atcs; } ;
typedef  int /*<<< orphan*/  acpi_handle ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_HANDLE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ATCS_FUNCTION_PCIE_DEVICE_READY_NOTIFICATION ; 
 int EINVAL ; 
 int EIO ; 
 union acpi_object* amdgpu_atcs_call (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (union acpi_object*) ; 

int amdgpu_acpi_pcie_notify_device_ready(struct amdgpu_device *adev)
{
	acpi_handle handle;
	union acpi_object *info;
	struct amdgpu_atcs *atcs = &adev->atcs;

	/* Get the device handle */
	handle = ACPI_HANDLE(&adev->pdev->dev);
	if (!handle)
		return -EINVAL;

	if (!atcs->functions.pcie_dev_rdy)
		return -EINVAL;

	info = amdgpu_atcs_call(handle, ATCS_FUNCTION_PCIE_DEVICE_READY_NOTIFICATION, NULL);
	if (!info)
		return -EIO;

	kfree(info);

	return 0;
}