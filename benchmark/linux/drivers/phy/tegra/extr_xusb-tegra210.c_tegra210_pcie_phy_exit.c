#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct tegra_xusb_lane {TYPE_1__* pad; } ;
struct phy {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  padctl; } ;

/* Variables and functions */
 struct tegra_xusb_lane* phy_get_drvdata (struct phy*) ; 
 int tegra210_xusb_padctl_disable (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tegra210_pcie_phy_exit(struct phy *phy)
{
	struct tegra_xusb_lane *lane = phy_get_drvdata(phy);

	return tegra210_xusb_padctl_disable(lane->pad->padctl);
}