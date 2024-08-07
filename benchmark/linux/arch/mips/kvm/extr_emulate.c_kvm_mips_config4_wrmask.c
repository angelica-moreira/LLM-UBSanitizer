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
 int MIPS_CONF4_KSCREXIST_SHIFT ; 
 unsigned int MIPS_CONF_M ; 

unsigned int kvm_mips_config4_wrmask(struct kvm_vcpu *vcpu)
{
	/* Config5 is optional */
	unsigned int mask = MIPS_CONF_M;

	/* KScrExist */
	mask |= 0xfc << MIPS_CONF4_KSCREXIST_SHIFT;

	return mask;
}