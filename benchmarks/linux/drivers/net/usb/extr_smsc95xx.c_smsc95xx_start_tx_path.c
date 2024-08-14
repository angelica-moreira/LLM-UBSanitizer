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
struct usbnet {scalar_t__* data; } ;
struct smsc95xx_priv {int /*<<< orphan*/  mac_cr; int /*<<< orphan*/  mac_cr_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CR ; 
 int /*<<< orphan*/  MAC_CR_TXEN_ ; 
 int /*<<< orphan*/  TX_CFG ; 
 int /*<<< orphan*/  TX_CFG_ON_ ; 
 int smsc95xx_write_reg (struct usbnet*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int smsc95xx_start_tx_path(struct usbnet *dev)
{
	struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);
	unsigned long flags;
	int ret;

	/* Enable Tx at MAC */
	spin_lock_irqsave(&pdata->mac_cr_lock, flags);
	pdata->mac_cr |= MAC_CR_TXEN_;
	spin_unlock_irqrestore(&pdata->mac_cr_lock, flags);

	ret = smsc95xx_write_reg(dev, MAC_CR, pdata->mac_cr);
	if (ret < 0)
		return ret;

	/* Enable Tx at SCSRs */
	return smsc95xx_write_reg(dev, TX_CFG, TX_CFG_ON_);
}