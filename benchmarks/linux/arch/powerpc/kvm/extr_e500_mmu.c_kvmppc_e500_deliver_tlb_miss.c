#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct kvmppc_vcpu_e500 {int /*<<< orphan*/ * gtlb_nv; } ;
struct TYPE_4__ {TYPE_1__* shared; } ;
struct kvm_vcpu {TYPE_2__ arch; } ;
typedef  int gva_t ;
struct TYPE_3__ {int mas4; int mas0; int mas1; int mas2; int mas7_3; int mas6; } ;

/* Variables and functions */
 int MAS0_ESEL (unsigned int) ; 
 int MAS0_NV (int /*<<< orphan*/ ) ; 
 int MAS0_TLBSEL (int) ; 
 int MAS1_TID (int /*<<< orphan*/ ) ; 
 int MAS1_TS ; 
 int MAS1_TSIZE (unsigned int) ; 
 int MAS1_VALID ; 
 int MAS2_ATTRIB_MASK ; 
 int MAS2_EPN ; 
 int MAS3_U0 ; 
 int MAS3_U1 ; 
 int MAS3_U2 ; 
 int MAS3_U3 ; 
 int MAS6_SAS ; 
 int MAS6_SPID1 ; 
 int get_cur_pid (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  get_tlbmiss_tid (struct kvm_vcpu*) ; 
 unsigned int gtlb0_get_next_victim (struct kvmppc_vcpu_e500*) ; 
 struct kvmppc_vcpu_e500* to_e500 (struct kvm_vcpu*) ; 

__attribute__((used)) static inline void kvmppc_e500_deliver_tlb_miss(struct kvm_vcpu *vcpu,
		gva_t eaddr, int as)
{
	struct kvmppc_vcpu_e500 *vcpu_e500 = to_e500(vcpu);
	unsigned int victim, tsized;
	int tlbsel;

	/* since we only have two TLBs, only lower bit is used. */
	tlbsel = (vcpu->arch.shared->mas4 >> 28) & 0x1;
	victim = (tlbsel == 0) ? gtlb0_get_next_victim(vcpu_e500) : 0;
	tsized = (vcpu->arch.shared->mas4 >> 7) & 0x1f;

	vcpu->arch.shared->mas0 = MAS0_TLBSEL(tlbsel) | MAS0_ESEL(victim)
		| MAS0_NV(vcpu_e500->gtlb_nv[tlbsel]);
	vcpu->arch.shared->mas1 = MAS1_VALID | (as ? MAS1_TS : 0)
		| MAS1_TID(get_tlbmiss_tid(vcpu))
		| MAS1_TSIZE(tsized);
	vcpu->arch.shared->mas2 = (eaddr & MAS2_EPN)
		| (vcpu->arch.shared->mas4 & MAS2_ATTRIB_MASK);
	vcpu->arch.shared->mas7_3 &= MAS3_U0 | MAS3_U1 | MAS3_U2 | MAS3_U3;
	vcpu->arch.shared->mas6 = (vcpu->arch.shared->mas6 & MAS6_SPID1)
		| (get_cur_pid(vcpu) << 16)
		| (as ? MAS6_SAS : 0);
}