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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  phy_id; } ;
struct jme_adapter {int /*<<< orphan*/  chip_main_rev; TYPE_1__ mii_if; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BMCR_PDOWN ; 
 int /*<<< orphan*/  MII_BMCR ; 
 int /*<<< orphan*/  jme_mdio_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jme_mdio_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jme_new_phy_on (struct jme_adapter*) ; 
 scalar_t__ new_phy_power_ctrl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
jme_phy_on(struct jme_adapter *jme)
{
	u32 bmcr;

	bmcr = jme_mdio_read(jme->dev, jme->mii_if.phy_id, MII_BMCR);
	bmcr &= ~BMCR_PDOWN;
	jme_mdio_write(jme->dev, jme->mii_if.phy_id, MII_BMCR, bmcr);

	if (new_phy_power_ctrl(jme->chip_main_rev))
		jme_new_phy_on(jme);
}