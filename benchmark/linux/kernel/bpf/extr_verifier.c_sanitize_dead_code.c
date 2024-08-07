#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  trap ;
struct bpf_verifier_env {TYPE_1__* prog; struct bpf_insn_aux_data* insn_aux_data; } ;
struct bpf_insn_aux_data {scalar_t__ seen; } ;
struct bpf_insn {int dummy; } ;
struct TYPE_2__ {int len; struct bpf_insn* insnsi; } ;

/* Variables and functions */
 int /*<<< orphan*/  BPF_JA ; 
 struct bpf_insn BPF_JMP_IMM (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (struct bpf_insn*,struct bpf_insn*,int) ; 

__attribute__((used)) static void sanitize_dead_code(struct bpf_verifier_env *env)
{
	struct bpf_insn_aux_data *aux_data = env->insn_aux_data;
	struct bpf_insn trap = BPF_JMP_IMM(BPF_JA, 0, 0, -1);
	struct bpf_insn *insn = env->prog->insnsi;
	const int insn_cnt = env->prog->len;
	int i;

	for (i = 0; i < insn_cnt; i++) {
		if (aux_data[i].seen)
			continue;
		memcpy(insn + i, &trap, sizeof(trap));
	}
}