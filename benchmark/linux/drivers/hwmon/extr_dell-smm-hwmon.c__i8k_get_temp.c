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
struct smm_regs {int eax; int ebx; } ;

/* Variables and functions */
 int I8K_SMM_GET_TEMP ; 
 scalar_t__ i8k_smm (struct smm_regs*) ; 

__attribute__((used)) static int _i8k_get_temp(int sensor)
{
	struct smm_regs regs = {
		.eax = I8K_SMM_GET_TEMP,
		.ebx = sensor & 0xff,
	};

	return i8k_smm(&regs) ? : regs.eax & 0xff;
}