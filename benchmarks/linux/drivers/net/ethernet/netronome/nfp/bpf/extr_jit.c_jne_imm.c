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
typedef  unsigned int u64 ;
typedef  int /*<<< orphan*/  swreg ;
struct nfp_prog {int dummy; } ;
struct bpf_insn {unsigned int imm; int dst_reg; int /*<<< orphan*/  off; } ;
struct nfp_insn_meta {struct bpf_insn insn; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALU_OP_NONE ; 
 int /*<<< orphan*/  ALU_OP_OR ; 
 int /*<<< orphan*/  ALU_OP_XOR ; 
 int /*<<< orphan*/  BR_BNE ; 
 int /*<<< orphan*/  emit_alu (struct nfp_prog*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_br (struct nfp_prog*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  imm_b (struct nfp_prog*) ; 
 int is_mbpf_jmp32 (struct nfp_insn_meta*) ; 
 int /*<<< orphan*/  reg_a (int) ; 
 int /*<<< orphan*/  reg_b (int) ; 
 int /*<<< orphan*/  reg_none () ; 
 int /*<<< orphan*/  ur_load_imm_any (struct nfp_prog*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int jne_imm(struct nfp_prog *nfp_prog, struct nfp_insn_meta *meta)
{
	const struct bpf_insn *insn = &meta->insn;
	u64 imm = insn->imm; /* sign extend */
	bool is_jmp32 = is_mbpf_jmp32(meta);
	swreg tmp_reg;

	if (!imm) {
		if (is_jmp32)
			emit_alu(nfp_prog, reg_none(), reg_none(), ALU_OP_NONE,
				 reg_b(insn->dst_reg * 2));
		else
			emit_alu(nfp_prog, reg_none(), reg_a(insn->dst_reg * 2),
				 ALU_OP_OR, reg_b(insn->dst_reg * 2 + 1));
		emit_br(nfp_prog, BR_BNE, insn->off, 0);
		return 0;
	}

	tmp_reg = ur_load_imm_any(nfp_prog, imm & ~0U, imm_b(nfp_prog));
	emit_alu(nfp_prog, reg_none(),
		 reg_a(insn->dst_reg * 2), ALU_OP_XOR, tmp_reg);
	emit_br(nfp_prog, BR_BNE, insn->off, 0);

	if (is_jmp32)
		return 0;

	tmp_reg = ur_load_imm_any(nfp_prog, imm >> 32, imm_b(nfp_prog));
	emit_alu(nfp_prog, reg_none(),
		 reg_a(insn->dst_reg * 2 + 1), ALU_OP_XOR, tmp_reg);
	emit_br(nfp_prog, BR_BNE, insn->off, 0);

	return 0;
}