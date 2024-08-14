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
 int /*<<< orphan*/  BARTS_MGCG_DISABLE_LENGTH ; 
 int /*<<< orphan*/  BARTS_MGCG_ENABLE_LENGTH ; 
 int /*<<< orphan*/  CAICOS_MGCG_DISABLE_LENGTH ; 
 int /*<<< orphan*/  CAICOS_MGCG_ENABLE_LENGTH ; 
 scalar_t__ CHIP_BARTS ; 
 scalar_t__ CHIP_CAICOS ; 
 scalar_t__ CHIP_TURKS ; 
 int /*<<< orphan*/  TURKS_MGCG_DISABLE_LENGTH ; 
 int /*<<< orphan*/  TURKS_MGCG_ENABLE_LENGTH ; 
 int /*<<< orphan*/ * barts_mgcg_disable ; 
 int /*<<< orphan*/  barts_mgcg_enable ; 
 int /*<<< orphan*/  btc_program_mgcg_hw_sequence (struct radeon_device*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * caicos_mgcg_disable ; 
 int /*<<< orphan*/  caicos_mgcg_enable ; 
 int /*<<< orphan*/ * turks_mgcg_disable ; 
 int /*<<< orphan*/  turks_mgcg_enable ; 

__attribute__((used)) static void btc_mg_clock_gating_enable(struct radeon_device *rdev,
				       bool enable)
{
	u32 count;
	const u32 *p = NULL;

	if (enable) {
		if (rdev->family == CHIP_BARTS) {
			p = (const u32 *)&barts_mgcg_enable;
			count = BARTS_MGCG_ENABLE_LENGTH;
		} else if (rdev->family == CHIP_TURKS) {
			p = (const u32 *)&turks_mgcg_enable;
			count = TURKS_MGCG_ENABLE_LENGTH;
		} else if (rdev->family == CHIP_CAICOS) {
			p = (const u32 *)&caicos_mgcg_enable;
			count = CAICOS_MGCG_ENABLE_LENGTH;
		} else
			return;
	} else {
		if (rdev->family == CHIP_BARTS) {
			p = (const u32 *)&barts_mgcg_disable[0];
			count = BARTS_MGCG_DISABLE_LENGTH;
		} else if (rdev->family == CHIP_TURKS) {
			p = (const u32 *)&turks_mgcg_disable[0];
			count = TURKS_MGCG_DISABLE_LENGTH;
		} else if (rdev->family == CHIP_CAICOS) {
			p = (const u32 *)&caicos_mgcg_disable[0];
			count = CAICOS_MGCG_DISABLE_LENGTH;
		} else
			return;
	}

	btc_program_mgcg_hw_sequence(rdev, p, count);
}