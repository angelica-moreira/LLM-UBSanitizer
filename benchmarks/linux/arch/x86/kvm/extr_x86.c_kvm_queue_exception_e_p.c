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
typedef  int /*<<< orphan*/  u32 ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kvm_multiple_exception (struct kvm_vcpu*,unsigned int,int,int /*<<< orphan*/ ,int,unsigned long,int) ; 

__attribute__((used)) static void kvm_queue_exception_e_p(struct kvm_vcpu *vcpu, unsigned nr,
				    u32 error_code, unsigned long payload)
{
	kvm_multiple_exception(vcpu, nr, true, error_code,
			       true, payload, false);
}