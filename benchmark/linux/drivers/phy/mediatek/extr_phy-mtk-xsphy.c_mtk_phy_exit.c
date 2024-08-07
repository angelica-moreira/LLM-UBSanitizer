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
struct xsphy_instance {int /*<<< orphan*/  ref_clk; } ;
struct phy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 struct xsphy_instance* phy_get_drvdata (struct phy*) ; 

__attribute__((used)) static int mtk_phy_exit(struct phy *phy)
{
	struct xsphy_instance *inst = phy_get_drvdata(phy);

	clk_disable_unprepare(inst->ref_clk);
	return 0;
}