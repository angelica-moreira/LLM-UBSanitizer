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
struct kvm_vcpu {int dummy; } ;
struct kvm_run {int dummy; } ;
typedef  int /*<<< orphan*/  gva_t ;

/* Variables and functions */
 int EMULATE_DONE ; 
 int EMULATE_FAIL ; 
#define  XOP_DCBTLS 137 
#define  XOP_EHPRIV 136 
#define  XOP_MFTMR 135 
#define  XOP_MSGCLR 134 
#define  XOP_MSGSND 133 
#define  XOP_TLBILX 132 
#define  XOP_TLBIVAX 131 
#define  XOP_TLBRE 130 
#define  XOP_TLBSX 129 
#define  XOP_TLBWE 128 
 int get_op (unsigned int) ; 
 int get_ra (unsigned int) ; 
 int get_rb (unsigned int) ; 
 int get_rt (unsigned int) ; 
 int /*<<< orphan*/  get_xop (unsigned int) ; 
 int kvmppc_booke_emulate_op (struct kvm_run*,struct kvm_vcpu*,unsigned int,int*) ; 
 int kvmppc_e500_emul_dcbtls (struct kvm_vcpu*) ; 
 int kvmppc_e500_emul_ehpriv (struct kvm_run*,struct kvm_vcpu*,unsigned int,int*) ; 
 int kvmppc_e500_emul_mftmr (struct kvm_vcpu*,unsigned int,int) ; 
 int kvmppc_e500_emul_msgclr (struct kvm_vcpu*,int) ; 
 int kvmppc_e500_emul_msgsnd (struct kvm_vcpu*,int) ; 
 int kvmppc_e500_emul_tlbilx (struct kvm_vcpu*,int,int /*<<< orphan*/ ) ; 
 int kvmppc_e500_emul_tlbivax (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 int kvmppc_e500_emul_tlbre (struct kvm_vcpu*) ; 
 int kvmppc_e500_emul_tlbsx (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 int kvmppc_e500_emul_tlbwe (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  kvmppc_get_ea_indexed (struct kvm_vcpu*,int,int) ; 

int kvmppc_core_emulate_op_e500(struct kvm_run *run, struct kvm_vcpu *vcpu,
				unsigned int inst, int *advance)
{
	int emulated = EMULATE_DONE;
	int ra = get_ra(inst);
	int rb = get_rb(inst);
	int rt = get_rt(inst);
	gva_t ea;

	switch (get_op(inst)) {
	case 31:
		switch (get_xop(inst)) {

		case XOP_DCBTLS:
			emulated = kvmppc_e500_emul_dcbtls(vcpu);
			break;

#ifdef CONFIG_KVM_E500MC
		case XOP_MSGSND:
			emulated = kvmppc_e500_emul_msgsnd(vcpu, rb);
			break;

		case XOP_MSGCLR:
			emulated = kvmppc_e500_emul_msgclr(vcpu, rb);
			break;
#endif

		case XOP_TLBRE:
			emulated = kvmppc_e500_emul_tlbre(vcpu);
			break;

		case XOP_TLBWE:
			emulated = kvmppc_e500_emul_tlbwe(vcpu);
			break;

		case XOP_TLBSX:
			ea = kvmppc_get_ea_indexed(vcpu, ra, rb);
			emulated = kvmppc_e500_emul_tlbsx(vcpu, ea);
			break;

		case XOP_TLBILX: {
			int type = rt & 0x3;
			ea = kvmppc_get_ea_indexed(vcpu, ra, rb);
			emulated = kvmppc_e500_emul_tlbilx(vcpu, type, ea);
			break;
		}

		case XOP_TLBIVAX:
			ea = kvmppc_get_ea_indexed(vcpu, ra, rb);
			emulated = kvmppc_e500_emul_tlbivax(vcpu, ea);
			break;

		case XOP_MFTMR:
			emulated = kvmppc_e500_emul_mftmr(vcpu, inst, rt);
			break;

		case XOP_EHPRIV:
			emulated = kvmppc_e500_emul_ehpriv(run, vcpu, inst,
							   advance);
			break;

		default:
			emulated = EMULATE_FAIL;
		}

		break;

	default:
		emulated = EMULATE_FAIL;
	}

	if (emulated == EMULATE_FAIL)
		emulated = kvmppc_booke_emulate_op(run, vcpu, inst, advance);

	return emulated;
}