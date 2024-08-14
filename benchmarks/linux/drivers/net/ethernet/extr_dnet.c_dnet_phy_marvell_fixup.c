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
 int phy_write (struct phy_device*,int,int) ; 

__attribute__((used)) static int dnet_phy_marvell_fixup(struct phy_device *phydev)
{
	return phy_write(phydev, 0x18, 0x4148);
}