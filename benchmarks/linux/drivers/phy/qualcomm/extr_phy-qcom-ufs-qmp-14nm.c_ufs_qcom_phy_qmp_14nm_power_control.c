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
struct ufs_qcom_phy {scalar_t__ mmio; } ;

/* Variables and functions */
 scalar_t__ UFS_PHY_POWER_DOWN_CONTROL ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static
void ufs_qcom_phy_qmp_14nm_power_control(struct ufs_qcom_phy *phy, bool val)
{
	writel_relaxed(val ? 0x1 : 0x0, phy->mmio + UFS_PHY_POWER_DOWN_CONTROL);
	/*
	 * Before any transactions involving PHY, ensure PHY knows
	 * that it's analog rail is powered ON (or OFF).
	 */
	mb();
}