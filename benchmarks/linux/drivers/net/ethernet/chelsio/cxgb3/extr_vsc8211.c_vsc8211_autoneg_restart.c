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
struct cphy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BMCR_ANRESTART ; 
 int BMCR_ISOLATE ; 
 int BMCR_PDOWN ; 
 int /*<<< orphan*/  MDIO_DEVAD_NONE ; 
 int /*<<< orphan*/  MII_BMCR ; 
 int t3_mdio_change_bits (struct cphy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int vsc8211_autoneg_restart(struct cphy *cphy)
{
	return t3_mdio_change_bits(cphy, MDIO_DEVAD_NONE, MII_BMCR,
				   BMCR_PDOWN | BMCR_ISOLATE,
				   BMCR_ANRESTART);
}