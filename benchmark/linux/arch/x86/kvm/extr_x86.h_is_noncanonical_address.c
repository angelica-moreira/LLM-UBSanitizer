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
typedef  scalar_t__ u64 ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 scalar_t__ get_canonical (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vcpu_virt_addr_bits (struct kvm_vcpu*) ; 

__attribute__((used)) static inline bool is_noncanonical_address(u64 la, struct kvm_vcpu *vcpu)
{
#ifdef CONFIG_X86_64
	return get_canonical(la, vcpu_virt_addr_bits(vcpu)) != la;
#else
	return false;
#endif
}