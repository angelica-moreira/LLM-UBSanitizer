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
struct bpf_reg_state {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  NOT_INIT ; 
 int /*<<< orphan*/  __mark_reg_unknown (struct bpf_reg_state*) ; 

__attribute__((used)) static void __mark_reg_not_init(struct bpf_reg_state *reg)
{
	__mark_reg_unknown(reg);
	reg->type = NOT_INIT;
}