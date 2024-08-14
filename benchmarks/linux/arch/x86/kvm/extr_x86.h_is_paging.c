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
 int /*<<< orphan*/  X86_CR0_PG ; 
 int /*<<< orphan*/  kvm_read_cr0_bits (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 int likely (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int is_paging(struct kvm_vcpu *vcpu)
{
	return likely(kvm_read_cr0_bits(vcpu, X86_CR0_PG));
}