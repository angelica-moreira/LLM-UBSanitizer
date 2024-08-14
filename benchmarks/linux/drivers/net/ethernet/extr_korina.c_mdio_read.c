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
struct net_device {int dummy; } ;
struct korina_private {int rx_irq; TYPE_1__* eth_regs; } ;
struct TYPE_2__ {int /*<<< orphan*/  miimrdd; int /*<<< orphan*/  miimcmd; int /*<<< orphan*/  miimaddr; int /*<<< orphan*/  miimcfg; } ;

/* Variables and functions */
 int ETH_MII_CMD_SCN ; 
 struct korina_private* netdev_priv (struct net_device*) ; 
 scalar_t__ readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int mdio_read(struct net_device *dev, int mii_id, int reg)
{
	struct korina_private *lp = netdev_priv(dev);
	int ret;

	mii_id = ((lp->rx_irq == 0x2c ? 1 : 0) << 8);

	writel(0, &lp->eth_regs->miimcfg);
	writel(0, &lp->eth_regs->miimcmd);
	writel(mii_id | reg, &lp->eth_regs->miimaddr);
	writel(ETH_MII_CMD_SCN, &lp->eth_regs->miimcmd);

	ret = (int)(readl(&lp->eth_regs->miimrdd));
	return ret;
}