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
typedef  int /*<<< orphan*/  u64 ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int __kvm_get_msr (struct kvm_vcpu*,unsigned int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int do_get_msr(struct kvm_vcpu *vcpu, unsigned index, u64 *data)
{
	return __kvm_get_msr(vcpu, index, data, true);
}