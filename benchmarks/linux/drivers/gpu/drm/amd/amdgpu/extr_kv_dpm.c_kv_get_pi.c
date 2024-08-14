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
struct kv_power_info {int dummy; } ;
struct TYPE_3__ {struct kv_power_info* priv; } ;
struct TYPE_4__ {TYPE_1__ dpm; } ;
struct amdgpu_device {TYPE_2__ pm; } ;

/* Variables and functions */

__attribute__((used)) static struct kv_power_info *kv_get_pi(struct amdgpu_device *adev)
{
	struct kv_power_info *pi = adev->pm.dpm.priv;

	return pi;
}