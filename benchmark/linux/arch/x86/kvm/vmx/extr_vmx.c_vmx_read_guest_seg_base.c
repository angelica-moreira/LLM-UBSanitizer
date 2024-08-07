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
typedef  int /*<<< orphan*/  ulong ;
struct TYPE_5__ {TYPE_1__* seg; } ;
struct vcpu_vmx {TYPE_2__ segment_cache; } ;
struct TYPE_6__ {int /*<<< orphan*/  base; } ;
struct TYPE_4__ {int /*<<< orphan*/  base; } ;

/* Variables and functions */
 int /*<<< orphan*/  SEG_FIELD_BASE ; 
 TYPE_3__* kvm_vmx_segment_fields ; 
 int /*<<< orphan*/  vmcs_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vmx_segment_cache_test_set (struct vcpu_vmx*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ulong vmx_read_guest_seg_base(struct vcpu_vmx *vmx, unsigned seg)
{
	ulong *p = &vmx->segment_cache.seg[seg].base;

	if (!vmx_segment_cache_test_set(vmx, seg, SEG_FIELD_BASE))
		*p = vmcs_readl(kvm_vmx_segment_fields[seg].base);
	return *p;
}