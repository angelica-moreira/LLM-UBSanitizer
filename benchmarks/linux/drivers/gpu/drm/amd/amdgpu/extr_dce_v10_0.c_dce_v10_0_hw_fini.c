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
struct TYPE_3__ {int num_pins; int /*<<< orphan*/ * pin; } ;
struct TYPE_4__ {TYPE_1__ audio; } ;
struct amdgpu_device {TYPE_2__ mode_info; } ;

/* Variables and functions */
 int /*<<< orphan*/  dce_v10_0_audio_enable (struct amdgpu_device*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dce_v10_0_hpd_fini (struct amdgpu_device*) ; 
 int /*<<< orphan*/  dce_v10_0_pageflip_interrupt_fini (struct amdgpu_device*) ; 

__attribute__((used)) static int dce_v10_0_hw_fini(void *handle)
{
	int i;
	struct amdgpu_device *adev = (struct amdgpu_device *)handle;

	dce_v10_0_hpd_fini(adev);

	for (i = 0; i < adev->mode_info.audio.num_pins; i++) {
		dce_v10_0_audio_enable(adev, &adev->mode_info.audio.pin[i], false);
	}

	dce_v10_0_pageflip_interrupt_fini(adev);

	return 0;
}