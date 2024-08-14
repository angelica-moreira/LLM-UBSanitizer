#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {scalar_t__ got; } ;
struct TYPE_9__ {scalar_t__ got; } ;
struct TYPE_8__ {scalar_t__ got; } ;
struct TYPE_7__ {scalar_t__ got; } ;
struct TYPE_6__ {scalar_t__ got; } ;
struct insn {TYPE_5__ immediate; TYPE_4__ displacement; TYPE_3__ sib; TYPE_2__ modrm; TYPE_1__ opcode; } ;

/* Variables and functions */

__attribute__((used)) static inline int insn_complete(struct insn *insn)
{
	return insn->opcode.got && insn->modrm.got && insn->sib.got &&
		insn->displacement.got && insn->immediate.got;
}