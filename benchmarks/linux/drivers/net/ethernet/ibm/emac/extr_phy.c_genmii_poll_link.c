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
struct mii_phy {scalar_t__ autoneg; } ;

/* Variables and functions */
 scalar_t__ AUTONEG_ENABLE ; 
 int BMSR_ANEGCOMPLETE ; 
 int BMSR_LSTATUS ; 
 int /*<<< orphan*/  MII_BMSR ; 
 int phy_read (struct mii_phy*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int genmii_poll_link(struct mii_phy *phy)
{
	int status;

	/* Clear latched value with dummy read */
	phy_read(phy, MII_BMSR);
	status = phy_read(phy, MII_BMSR);
	if (status < 0 || (status & BMSR_LSTATUS) == 0)
		return 0;
	if (phy->autoneg == AUTONEG_ENABLE && !(status & BMSR_ANEGCOMPLETE))
		return 0;
	return 1;
}