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
struct TYPE_3__ {int double_offchip_lds_buf; } ;
struct TYPE_4__ {TYPE_1__ config; } ;
struct amdgpu_device {int asic_type; TYPE_2__ gfx; } ;

/* Variables and functions */
#define  CHIP_CARRIZO 129 
#define  CHIP_STONEY 128 

__attribute__((used)) static void gfx_v8_0_config_init(struct amdgpu_device *adev)
{
	switch (adev->asic_type) {
	default:
		adev->gfx.config.double_offchip_lds_buf = 1;
		break;
	case CHIP_CARRIZO:
	case CHIP_STONEY:
		adev->gfx.config.double_offchip_lds_buf = 0;
		break;
	}
}