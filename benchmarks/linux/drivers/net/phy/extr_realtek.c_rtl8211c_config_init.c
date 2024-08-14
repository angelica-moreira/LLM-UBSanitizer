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
struct phy_device {int dummy; } ;

/* Variables and functions */
 int CTL1000_AS_MASTER ; 
 int CTL1000_ENABLE_MASTER ; 
 int /*<<< orphan*/  MII_CTRL1000 ; 
 int phy_set_bits (struct phy_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int rtl8211c_config_init(struct phy_device *phydev)
{
	/* RTL8211C has an issue when operating in Gigabit slave mode */
	return phy_set_bits(phydev, MII_CTRL1000,
			    CTL1000_ENABLE_MASTER | CTL1000_AS_MASTER);
}