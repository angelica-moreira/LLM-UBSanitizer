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
struct phy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PHY_CTRL ; 
 int /*<<< orphan*/  PHY_CTRL_PHY_PWDN ; 
 int /*<<< orphan*/  rcar_gen3_phy_pcie_modify_reg (struct phy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int r8a77980_phy_pcie_power_on(struct phy *p)
{
	/* Power on the PCIe PHY */
	rcar_gen3_phy_pcie_modify_reg(p, PHY_CTRL, PHY_CTRL_PHY_PWDN, 0);

	return 0;
}