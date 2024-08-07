#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_5__ {TYPE_1__* seg; } ;
struct vcpu_vmx {TYPE_2__ segment_cache; } ;
struct TYPE_6__ {int /*<<< orphan*/  ar_bytes; } ;
struct TYPE_4__ {int /*<<< orphan*/  ar; } ;

/* Variables and functions */
 int /*<<< orphan*/  SEG_FIELD_AR ; 
 TYPE_3__* kvm_vmx_segment_fields ; 
 int /*<<< orphan*/  vmcs_read32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vmx_segment_cache_test_set (struct vcpu_vmx*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 vmx_read_guest_seg_ar(struct vcpu_vmx *vmx, unsigned seg)
{
	u32 *p = &vmx->segment_cache.seg[seg].ar;

	if (!vmx_segment_cache_test_set(vmx, seg, SEG_FIELD_AR))
		*p = vmcs_read32(kvm_vmx_segment_fields[seg].ar_bytes);
	return *p;
}