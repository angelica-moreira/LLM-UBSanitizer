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
typedef  scalar_t__ u32 ;
struct radeon_device {scalar_t__ usec_timeout; } ;

/* Variables and functions */
 scalar_t__ GFX_CLOCK_STATUS ; 
 scalar_t__ GFX_POWER_STATUS ; 
 scalar_t__ MESSAGE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MSG_ENTER_RLC_SAFE_MODE ; 
 scalar_t__ REQ ; 
 int /*<<< orphan*/  RLC_GPM_STAT ; 
 int /*<<< orphan*/  RLC_GPR_REG2 ; 
 scalar_t__ RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 

void cik_enter_rlc_safe_mode(struct radeon_device *rdev)
{
	u32 tmp, i, mask;

	tmp = REQ | MESSAGE(MSG_ENTER_RLC_SAFE_MODE);
	WREG32(RLC_GPR_REG2, tmp);

	mask = GFX_POWER_STATUS | GFX_CLOCK_STATUS;
	for (i = 0; i < rdev->usec_timeout; i++) {
		if ((RREG32(RLC_GPM_STAT) & mask) == mask)
			break;
		udelay(1);
	}

	for (i = 0; i < rdev->usec_timeout; i++) {
		if ((RREG32(RLC_GPR_REG2) & REQ) == 0)
			break;
		udelay(1);
	}
}