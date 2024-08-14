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
typedef  int /*<<< orphan*/  u32 ;
struct radeon_device {scalar_t__ family; } ;

/* Variables and functions */
 int /*<<< orphan*/  BARTS_SYSLS_DISABLE_LENGTH ; 
 int /*<<< orphan*/  BARTS_SYSLS_ENABLE_LENGTH ; 
 int /*<<< orphan*/  CAICOS_SYSLS_DISABLE_LENGTH ; 
 int /*<<< orphan*/  CAICOS_SYSLS_ENABLE_LENGTH ; 
 scalar_t__ CHIP_BARTS ; 
 scalar_t__ CHIP_CAICOS ; 
 scalar_t__ CHIP_TURKS ; 
 int /*<<< orphan*/  TURKS_SYSLS_DISABLE_LENGTH ; 
 int /*<<< orphan*/  TURKS_SYSLS_ENABLE_LENGTH ; 
 int /*<<< orphan*/  barts_sysls_disable ; 
 int /*<<< orphan*/  barts_sysls_enable ; 
 int /*<<< orphan*/  btc_program_mgcg_hw_sequence (struct radeon_device*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  caicos_sysls_disable ; 
 int /*<<< orphan*/  caicos_sysls_enable ; 
 int /*<<< orphan*/  turks_sysls_disable ; 
 int /*<<< orphan*/  turks_sysls_enable ; 

__attribute__((used)) static void btc_ls_clock_gating_enable(struct radeon_device *rdev,
				       bool enable)
{
	u32 count;
	const u32 *p = NULL;

	if (enable) {
		if (rdev->family == CHIP_BARTS) {
			p = (const u32 *)&barts_sysls_enable;
			count = BARTS_SYSLS_ENABLE_LENGTH;
		} else if (rdev->family == CHIP_TURKS) {
			p = (const u32 *)&turks_sysls_enable;
			count = TURKS_SYSLS_ENABLE_LENGTH;
		} else if (rdev->family == CHIP_CAICOS) {
			p = (const u32 *)&caicos_sysls_enable;
			count = CAICOS_SYSLS_ENABLE_LENGTH;
		} else
			return;
	} else {
		if (rdev->family == CHIP_BARTS) {
			p = (const u32 *)&barts_sysls_disable;
			count = BARTS_SYSLS_DISABLE_LENGTH;
		} else if (rdev->family == CHIP_TURKS) {
			p = (const u32 *)&turks_sysls_disable;
			count = TURKS_SYSLS_DISABLE_LENGTH;
		} else if (rdev->family == CHIP_CAICOS) {
			p = (const u32 *)&caicos_sysls_disable;
			count = CAICOS_SYSLS_DISABLE_LENGTH;
		} else
			return;
	}

	btc_program_mgcg_hw_sequence(rdev, p, count);
}