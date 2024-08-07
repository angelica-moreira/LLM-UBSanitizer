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
typedef  int u64 ;
struct kvm_vcpu {int dummy; } ;
struct coproc_reg {scalar_t__ reg; } ;

/* Variables and functions */
 int vcpu_cp15 (struct kvm_vcpu*,scalar_t__) ; 

__attribute__((used)) static inline u64 vcpu_cp15_reg64_get(struct kvm_vcpu *vcpu,
				      const struct coproc_reg *r)
{
	u64 val;

	val = vcpu_cp15(vcpu, r->reg + 1);
	val = val << 32;
	val = val | vcpu_cp15(vcpu, r->reg);
	return val;
}