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
typedef  int u32 ;
struct temac_local {int /*<<< orphan*/  dev; int /*<<< orphan*/  indirect_lock; } ;
struct mii_bus {struct temac_local* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  XTE_LSW0_OFFSET ; 
 int /*<<< orphan*/  XTE_MIIMAI_OFFSET ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 
 int temac_indirect_in32_locked (struct temac_local*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  temac_iow (struct temac_local*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int temac_mdio_read(struct mii_bus *bus, int phy_id, int reg)
{
	struct temac_local *lp = bus->priv;
	u32 rc;
	unsigned long flags;

	/* Write the PHY address to the MIIM Access Initiator register.
	 * When the transfer completes, the PHY register value will appear
	 * in the LSW0 register */
	spin_lock_irqsave(lp->indirect_lock, flags);
	temac_iow(lp, XTE_LSW0_OFFSET, (phy_id << 5) | reg);
	rc = temac_indirect_in32_locked(lp, XTE_MIIMAI_OFFSET);
	spin_unlock_irqrestore(lp->indirect_lock, flags);

	dev_dbg(lp->dev, "temac_mdio_read(phy_id=%i, reg=%x) == %x\n",
		phy_id, reg, rc);

	return rc;
}