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
struct TYPE_3__ {int num_types; int /*<<< orphan*/ * funcs; } ;
struct TYPE_4__ {TYPE_1__ irq; } ;
struct amdgpu_device {TYPE_2__ vce; } ;

/* Variables and functions */
 int /*<<< orphan*/  vce_v3_0_irq_funcs ; 

__attribute__((used)) static void vce_v3_0_set_irq_funcs(struct amdgpu_device *adev)
{
	adev->vce.irq.num_types = 1;
	adev->vce.irq.funcs = &vce_v3_0_irq_funcs;
}