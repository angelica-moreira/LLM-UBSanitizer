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
struct TYPE_2__ {struct kvm_lapic* apic; } ;
struct kvm_vcpu {TYPE_1__ arch; } ;
struct kvm_lapic_irq {int /*<<< orphan*/  trig_mode; int /*<<< orphan*/  level; int /*<<< orphan*/  vector; int /*<<< orphan*/  delivery_mode; } ;
struct kvm_lapic {int dummy; } ;
struct dest_map {int dummy; } ;

/* Variables and functions */
 int __apic_accept_irq (struct kvm_lapic*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dest_map*) ; 

int kvm_apic_set_irq(struct kvm_vcpu *vcpu, struct kvm_lapic_irq *irq,
		     struct dest_map *dest_map)
{
	struct kvm_lapic *apic = vcpu->arch.apic;

	return __apic_accept_irq(apic, irq->delivery_mode, irq->vector,
			irq->level, irq->trig_mode, dest_map);
}