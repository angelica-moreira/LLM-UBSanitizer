#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_6__ {TYPE_2__* dc; } ;
struct amdgpu_device {TYPE_3__ dm; } ;
struct TYPE_4__ {int /*<<< orphan*/  visual_confirm; } ;
struct TYPE_5__ {TYPE_1__ debug; } ;

/* Variables and functions */

__attribute__((used)) static int visual_confirm_get(void *data, u64 *val)
{
	struct amdgpu_device *adev = data;

	*val = adev->dm.dc->debug.visual_confirm;

	return 0;
}