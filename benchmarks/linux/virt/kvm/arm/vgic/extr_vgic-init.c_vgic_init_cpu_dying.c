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
struct TYPE_2__ {int /*<<< orphan*/  maint_irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  disable_percpu_irq (int /*<<< orphan*/ ) ; 
 TYPE_1__ kvm_vgic_global_state ; 

__attribute__((used)) static int vgic_init_cpu_dying(unsigned int cpu)
{
	disable_percpu_irq(kvm_vgic_global_state.maint_irq);
	return 0;
}