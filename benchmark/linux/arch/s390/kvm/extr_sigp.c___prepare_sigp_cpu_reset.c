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
typedef  int /*<<< orphan*/  u8 ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 

__attribute__((used)) static int __prepare_sigp_cpu_reset(struct kvm_vcpu *vcpu,
				    struct kvm_vcpu *dst_vcpu, u8 order_code)
{
	/* handle (INITIAL) CPU RESET in user space */
	return -EOPNOTSUPP;
}