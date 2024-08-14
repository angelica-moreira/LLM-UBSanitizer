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
struct uniphier_u3hsphy_priv {int /*<<< orphan*/  clk_ext; int /*<<< orphan*/  clk; int /*<<< orphan*/  rst; scalar_t__ vbus; } ;
struct phy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 struct uniphier_u3hsphy_priv* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  regulator_disable (scalar_t__) ; 
 int /*<<< orphan*/  reset_control_assert (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int uniphier_u3hsphy_power_off(struct phy *phy)
{
	struct uniphier_u3hsphy_priv *priv = phy_get_drvdata(phy);

	if (priv->vbus)
		regulator_disable(priv->vbus);

	reset_control_assert(priv->rst);
	clk_disable_unprepare(priv->clk);
	clk_disable_unprepare(priv->clk_ext);

	return 0;
}