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
struct TYPE_5__ {int /*<<< orphan*/ * funcs; } ;
struct TYPE_4__ {int /*<<< orphan*/ * funcs; scalar_t__ num_types; } ;
struct TYPE_6__ {TYPE_2__ illegal_inst_irq; TYPE_1__ trap_irq; scalar_t__ num_instances; } ;
struct amdgpu_device {TYPE_3__ sdma; } ;

/* Variables and functions */
 scalar_t__ AMDGPU_SDMA_IRQ_INSTANCE0 ; 
 int /*<<< orphan*/  sdma_v5_0_illegal_inst_irq_funcs ; 
 int /*<<< orphan*/  sdma_v5_0_trap_irq_funcs ; 

__attribute__((used)) static void sdma_v5_0_set_irq_funcs(struct amdgpu_device *adev)
{
	adev->sdma.trap_irq.num_types = AMDGPU_SDMA_IRQ_INSTANCE0 +
					adev->sdma.num_instances;
	adev->sdma.trap_irq.funcs = &sdma_v5_0_trap_irq_funcs;
	adev->sdma.illegal_inst_irq.funcs = &sdma_v5_0_illegal_inst_irq_funcs;
}