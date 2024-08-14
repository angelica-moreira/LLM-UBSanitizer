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
typedef  int /*<<< orphan*/  u32 ;
struct __vxge_hw_vpath_handle {TYPE_1__* vpath; } ;
struct __vxge_hw_device {TYPE_2__* common_reg; } ;
struct TYPE_4__ {int /*<<< orphan*/ * set_msix_mask_vect; } ;
struct TYPE_3__ {struct __vxge_hw_device* hldev; } ;

/* Variables and functions */
 int /*<<< orphan*/  __vxge_hw_pio_mem_write32_upper (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ vxge_bVALn (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  vxge_mBIT (int) ; 

void
vxge_hw_vpath_msix_mask(struct __vxge_hw_vpath_handle *vp, int msix_id)
{
	struct __vxge_hw_device *hldev = vp->vpath->hldev;
	__vxge_hw_pio_mem_write32_upper(
		(u32) vxge_bVALn(vxge_mBIT(msix_id  >> 2), 0, 32),
		&hldev->common_reg->set_msix_mask_vect[msix_id % 4]);
}