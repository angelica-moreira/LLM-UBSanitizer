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
struct TYPE_3__ {int /*<<< orphan*/  reference_freq; } ;
struct TYPE_4__ {TYPE_1__ spll; } ;
struct amdgpu_device {TYPE_2__ clock; } ;

/* Variables and functions */

__attribute__((used)) static u32 nv_get_xclk(struct amdgpu_device *adev)
{
	return adev->clock.spll.reference_freq;
}