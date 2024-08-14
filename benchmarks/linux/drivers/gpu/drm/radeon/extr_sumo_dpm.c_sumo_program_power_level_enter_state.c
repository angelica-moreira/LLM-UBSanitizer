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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CG_SCLK_DPM_CTRL_5 ; 
 int /*<<< orphan*/  SCLK_FSTATE_BOOTUP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SCLK_FSTATE_BOOTUP_MASK ; 
 int /*<<< orphan*/  WREG32_P (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sumo_program_power_level_enter_state(struct radeon_device *rdev)
{
	WREG32_P(CG_SCLK_DPM_CTRL_5, SCLK_FSTATE_BOOTUP(0), ~SCLK_FSTATE_BOOTUP_MASK);
}