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
struct ksz_hw {scalar_t__ io; } ;
struct hw_regs {int end; int start; } ;
struct ethtool_regs {scalar_t__ version; } ;
struct dev_priv {struct dev_info* adapter; } ;
struct dev_info {int /*<<< orphan*/  lock; int /*<<< orphan*/  pdev; struct ksz_hw hw; } ;

/* Variables and functions */
 struct hw_regs* hw_regs_range ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct dev_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  pci_read_config_dword (int /*<<< orphan*/ ,int,int*) ; 
 int readl (scalar_t__) ; 

__attribute__((used)) static void netdev_get_regs(struct net_device *dev, struct ethtool_regs *regs,
	void *ptr)
{
	struct dev_priv *priv = netdev_priv(dev);
	struct dev_info *hw_priv = priv->adapter;
	struct ksz_hw *hw = &hw_priv->hw;
	int *buf = (int *) ptr;
	struct hw_regs *range = hw_regs_range;
	int len;

	mutex_lock(&hw_priv->lock);
	regs->version = 0;
	for (len = 0; len < 0x40; len += 4) {
		pci_read_config_dword(hw_priv->pdev, len, buf);
		buf++;
	}
	while (range->end > range->start) {
		for (len = range->start; len < range->end; len += 4) {
			*buf = readl(hw->io + len);
			buf++;
		}
		range++;
	}
	mutex_unlock(&hw_priv->lock);
}