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
typedef  int /*<<< orphan*/  u16 ;
struct phy_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MII_BCM54XX_EXP_DATA ; 
 int /*<<< orphan*/  MII_BCM54XX_EXP_SEL ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int bcm_phy_write_exp(struct phy_device *phydev, u16 reg, u16 val)
{
	int rc;

	rc = phy_write(phydev, MII_BCM54XX_EXP_SEL, reg);
	if (rc < 0)
		return rc;

	return phy_write(phydev, MII_BCM54XX_EXP_DATA, val);
}