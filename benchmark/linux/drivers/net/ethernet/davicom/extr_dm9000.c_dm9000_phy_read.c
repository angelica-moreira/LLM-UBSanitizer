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
struct net_device {int dummy; } ;
struct board_info {int /*<<< orphan*/  addr_lock; int /*<<< orphan*/  lock; int /*<<< orphan*/  io_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  DM9000_EPAR ; 
 int /*<<< orphan*/  DM9000_EPCR ; 
 int /*<<< orphan*/  DM9000_EPDRH ; 
 int /*<<< orphan*/  DM9000_EPDRL ; 
 int DM9000_PHY ; 
 int EPCR_EPOS ; 
 int EPCR_ERPRR ; 
 int /*<<< orphan*/  dm9000_dbg (struct board_info*,int,char*,int,int) ; 
 int /*<<< orphan*/  dm9000_msleep (struct board_info*,int) ; 
 int ior (struct board_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iow (struct board_info*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct board_info* netdev_priv (struct net_device*) ; 
 unsigned int readb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writeb (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
dm9000_phy_read(struct net_device *dev, int phy_reg_unused, int reg)
{
	struct board_info *db = netdev_priv(dev);
	unsigned long flags;
	unsigned int reg_save;
	int ret;

	mutex_lock(&db->addr_lock);

	spin_lock_irqsave(&db->lock, flags);

	/* Save previous register address */
	reg_save = readb(db->io_addr);

	/* Fill the phyxcer register into REG_0C */
	iow(db, DM9000_EPAR, DM9000_PHY | reg);

	/* Issue phyxcer read command */
	iow(db, DM9000_EPCR, EPCR_ERPRR | EPCR_EPOS);

	writeb(reg_save, db->io_addr);
	spin_unlock_irqrestore(&db->lock, flags);

	dm9000_msleep(db, 1);		/* Wait read complete */

	spin_lock_irqsave(&db->lock, flags);
	reg_save = readb(db->io_addr);

	iow(db, DM9000_EPCR, 0x0);	/* Clear phyxcer read command */

	/* The read data keeps on REG_0D & REG_0E */
	ret = (ior(db, DM9000_EPDRH) << 8) | ior(db, DM9000_EPDRL);

	/* restore the previous address */
	writeb(reg_save, db->io_addr);
	spin_unlock_irqrestore(&db->lock, flags);

	mutex_unlock(&db->addr_lock);

	dm9000_dbg(db, 5, "phy_read[%02x] -> %04x\n", reg, ret);
	return ret;
}