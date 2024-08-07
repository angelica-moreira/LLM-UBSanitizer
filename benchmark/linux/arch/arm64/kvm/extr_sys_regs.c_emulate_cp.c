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
struct sys_reg_params {int dummy; } ;
struct sys_reg_desc {int dummy; } ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 struct sys_reg_desc* find_reg (struct sys_reg_params*,struct sys_reg_desc const*,size_t) ; 
 int /*<<< orphan*/  perform_access (struct kvm_vcpu*,struct sys_reg_params*,struct sys_reg_desc const*) ; 

__attribute__((used)) static int emulate_cp(struct kvm_vcpu *vcpu,
		      struct sys_reg_params *params,
		      const struct sys_reg_desc *table,
		      size_t num)
{
	const struct sys_reg_desc *r;

	if (!table)
		return -1;	/* Not handled */

	r = find_reg(params, table, num);

	if (r) {
		perform_access(vcpu, params, r);
		return 0;
	}

	/* Not handled */
	return -1;
}