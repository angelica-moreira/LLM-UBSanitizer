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
struct bpf_verifier_env {int dummy; } ;
struct bpf_reg_state {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 struct bpf_reg_state* reg_state (struct bpf_verifier_env*,int) ; 
 int type_is_sk_pointer (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool is_sk_reg(struct bpf_verifier_env *env, int regno)
{
	const struct bpf_reg_state *reg = reg_state(env, regno);

	return type_is_sk_pointer(reg->type);
}