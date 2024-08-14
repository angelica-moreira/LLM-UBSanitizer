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
struct TYPE_2__ {int nvm; scalar_t__ vram_base_offset; } ;
struct radeon_device {TYPE_1__ vm_manager; } ;

/* Variables and functions */

int si_vm_init(struct radeon_device *rdev)
{
	/* number of VMs */
	rdev->vm_manager.nvm = 16;
	/* base offset of vram pages */
	rdev->vm_manager.vram_base_offset = 0;

	return 0;
}