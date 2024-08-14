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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct usbnet {int /*<<< orphan*/  phy_mutex; TYPE_1__* udev; } ;
typedef  int __le16 ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  HIF_REG_PHY_CMD1 ; 
 int HIF_REG_PHY_CMD1_PHYADDR ; 
 int HIF_REG_PHY_CMD1_WRITE ; 
 int HIF_REG_PHY_CMD2_PEND_FLAG_BIT ; 
 int HIF_REG_PHY_CMD2_READY_FLAG_BIT ; 
 int /*<<< orphan*/  HIF_REG_PHY_DATA ; 
 int cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ,int) ; 
 int mcs7830_get_reg (struct usbnet*,int /*<<< orphan*/ ,int,int*) ; 
 int mcs7830_set_reg (struct usbnet*,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int mcs7830_write_phy(struct usbnet *dev, u8 index, u16 val)
{
	int ret;
	int i;
	__le16 le_val;

	u8 cmd[2] = {
		HIF_REG_PHY_CMD1_WRITE | HIF_REG_PHY_CMD1_PHYADDR,
		HIF_REG_PHY_CMD2_PEND_FLAG_BIT | (index & 0x1F),
	};

	mutex_lock(&dev->phy_mutex);

	/* write the new register contents */
	le_val = cpu_to_le16(val);
	ret = mcs7830_set_reg(dev, HIF_REG_PHY_DATA, 2, &le_val);
	if (ret < 0)
		goto out;

	/* write the MII command */
	ret = mcs7830_set_reg(dev, HIF_REG_PHY_CMD1, 2, cmd);
	if (ret < 0)
		goto out;

	/* wait for the command to be accepted by the PHY */
	for (i = 0; i < 10; i++) {
		ret = mcs7830_get_reg(dev, HIF_REG_PHY_CMD1, 2, cmd);
		if ((ret < 0) || (cmd[1] & HIF_REG_PHY_CMD2_READY_FLAG_BIT))
			break;
		ret = -EIO;
		msleep(1);
	}
	if (ret < 0)
		goto out;

	ret = 0;
	dev_dbg(&dev->udev->dev, "write PHY reg %02x: %04x (%d tries)\n",
		index, val, i);
out:
	mutex_unlock(&dev->phy_mutex);
	return ret;
}