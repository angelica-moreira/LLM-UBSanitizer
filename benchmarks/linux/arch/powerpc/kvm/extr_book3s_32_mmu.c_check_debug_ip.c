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
struct TYPE_3__ {scalar_t__ nip; } ;
struct TYPE_4__ {TYPE_1__ regs; } ;
struct kvm_vcpu {TYPE_2__ arch; } ;

/* Variables and functions */
 scalar_t__ DEBUG_MMU_PTE_IP ; 

__attribute__((used)) static inline bool check_debug_ip(struct kvm_vcpu *vcpu)
{
#ifdef DEBUG_MMU_PTE_IP
	return vcpu->arch.regs.nip == DEBUG_MMU_PTE_IP;
#else
	return true;
#endif
}