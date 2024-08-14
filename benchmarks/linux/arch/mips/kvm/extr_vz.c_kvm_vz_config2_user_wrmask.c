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
 unsigned int MIPS_CONF_M ; 
 unsigned int kvm_vz_config2_guest_wrmask (struct kvm_vcpu*) ; 

__attribute__((used)) static inline unsigned int kvm_vz_config2_user_wrmask(struct kvm_vcpu *vcpu)
{
	return kvm_vz_config2_guest_wrmask(vcpu) | MIPS_CONF_M;
}