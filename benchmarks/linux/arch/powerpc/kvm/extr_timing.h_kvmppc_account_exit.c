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

/* Variables and functions */
 int /*<<< orphan*/  kvmppc_account_exit_stat (struct kvm_vcpu*,int) ; 
 int /*<<< orphan*/  kvmppc_set_exit_type (struct kvm_vcpu*,int) ; 

__attribute__((used)) static inline void kvmppc_account_exit(struct kvm_vcpu *vcpu, int type)
{
	kvmppc_set_exit_type(vcpu, type);
	kvmppc_account_exit_stat(vcpu, type);
}