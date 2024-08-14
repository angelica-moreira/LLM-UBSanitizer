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
 int adin_mdix_update (struct phy_device*) ; 
 int genphy_read_status (struct phy_device*) ; 

__attribute__((used)) static int adin_read_status(struct phy_device *phydev)
{
	int ret;

	ret = adin_mdix_update(phydev);
	if (ret < 0)
		return ret;

	return genphy_read_status(phydev);
}