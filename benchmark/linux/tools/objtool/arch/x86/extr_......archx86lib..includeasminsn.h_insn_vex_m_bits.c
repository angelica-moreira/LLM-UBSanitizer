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
struct TYPE_2__ {int nbytes; int /*<<< orphan*/ * bytes; } ;
struct insn {TYPE_1__ vex_prefix; } ;
typedef  int /*<<< orphan*/  insn_byte_t ;

/* Variables and functions */
 int /*<<< orphan*/  X86_EVEX_M (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X86_VEX2_M ; 
 int /*<<< orphan*/  X86_VEX3_M (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline insn_byte_t insn_vex_m_bits(struct insn *insn)
{
	if (insn->vex_prefix.nbytes == 2)	/* 2 bytes VEX */
		return X86_VEX2_M;
	else if (insn->vex_prefix.nbytes == 3)	/* 3 bytes VEX */
		return X86_VEX3_M(insn->vex_prefix.bytes[1]);
	else					/* EVEX */
		return X86_EVEX_M(insn->vex_prefix.bytes[1]);
}