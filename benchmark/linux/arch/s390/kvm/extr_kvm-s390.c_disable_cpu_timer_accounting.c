#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __disable_cpu_timer_accounting (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable () ; 

__attribute__((used)) static void disable_cpu_timer_accounting(struct kvm_vcpu *vcpu)
{
	preempt_disable(); /* protect from TOD sync and vcpu_load/put */
	__disable_cpu_timer_accounting(vcpu);
	preempt_enable();
}