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
struct phy_device {scalar_t__ interrupts; } ;

/* Variables and functions */
 int /*<<< orphan*/  MII_BCM54XX_ECR ; 
 int MII_BCM54XX_ECR_IM ; 
 scalar_t__ PHY_INTERRUPT_ENABLED ; 
 int phy_read (struct phy_device*,int /*<<< orphan*/ ) ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int) ; 

int bcm_phy_config_intr(struct phy_device *phydev)
{
	int reg;

	reg = phy_read(phydev, MII_BCM54XX_ECR);
	if (reg < 0)
		return reg;

	if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
		reg &= ~MII_BCM54XX_ECR_IM;
	else
		reg |= MII_BCM54XX_ECR_IM;

	return phy_write(phydev, MII_BCM54XX_ECR, reg);
}