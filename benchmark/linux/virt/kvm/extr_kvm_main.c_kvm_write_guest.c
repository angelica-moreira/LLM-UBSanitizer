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
typedef  int gpa_t ;
typedef  int gfn_t ;

/* Variables and functions */
 int PAGE_SHIFT ; 
 int kvm_write_guest_page (struct kvm*,int,void const*,int,int) ; 
 int next_segment (unsigned long,int) ; 
 int offset_in_page (int) ; 

int kvm_write_guest(struct kvm *kvm, gpa_t gpa, const void *data,
		    unsigned long len)
{
	gfn_t gfn = gpa >> PAGE_SHIFT;
	int seg;
	int offset = offset_in_page(gpa);
	int ret;

	while ((seg = next_segment(len, offset)) != 0) {
		ret = kvm_write_guest_page(kvm, gfn, data, offset, seg);
		if (ret < 0)
			return ret;
		offset = 0;
		len -= seg;
		data += seg;
		++gfn;
	}
	return 0;
}