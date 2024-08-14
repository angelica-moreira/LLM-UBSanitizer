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
struct kvm_msr_entry {unsigned int index; int /*<<< orphan*/  data; } ;

/* Variables and functions */
 int kvm_get_msr_feature (struct kvm_msr_entry*) ; 

__attribute__((used)) static int do_get_msr_feature(struct kvm_vcpu *vcpu, unsigned index, u64 *data)
{
	struct kvm_msr_entry msr;
	int r;

	msr.index = index;
	r = kvm_get_msr_feature(&msr);
	if (r)
		return r;

	*data = msr.data;

	return 0;
}