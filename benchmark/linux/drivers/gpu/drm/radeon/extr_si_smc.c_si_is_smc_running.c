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
typedef  int u32 ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int CK_DISABLE ; 
 int RREG32_SMC (int /*<<< orphan*/ ) ; 
 int RST_REG ; 
 int /*<<< orphan*/  SMC_SYSCON_CLOCK_CNTL_0 ; 
 int /*<<< orphan*/  SMC_SYSCON_RESET_CNTL ; 

bool si_is_smc_running(struct radeon_device *rdev)
{
	u32 rst = RREG32_SMC(SMC_SYSCON_RESET_CNTL);
	u32 clk = RREG32_SMC(SMC_SYSCON_CLOCK_CNTL_0);

	if (!(rst & RST_REG) && !(clk & CK_DISABLE))
		return true;

	return false;
}