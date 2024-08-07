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
struct kvm {int dummy; } ;

/* Variables and functions */
 int kvm_read_guest (struct kvm*,unsigned long,unsigned long*,int) ; 

__attribute__((used)) static int deref_table(struct kvm *kvm, unsigned long gpa, unsigned long *val)
{
	return kvm_read_guest(kvm, gpa, val, sizeof(*val));
}