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
struct ltq_vrx200_pcie_phy_priv {int /*<<< orphan*/  pdi_clk; int /*<<< orphan*/  phy_clk; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 struct ltq_vrx200_pcie_phy_priv* phy_get_drvdata (struct phy*) ; 

__attribute__((used)) static int ltq_vrx200_pcie_phy_power_off(struct phy *phy)
{
	struct ltq_vrx200_pcie_phy_priv *priv = phy_get_drvdata(phy);

	clk_disable_unprepare(priv->phy_clk);
	clk_disable_unprepare(priv->pdi_clk);

	return 0;
}