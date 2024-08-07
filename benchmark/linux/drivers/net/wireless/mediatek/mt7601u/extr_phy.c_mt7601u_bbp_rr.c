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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct mt7601u_dev {int /*<<< orphan*/  dev; int /*<<< orphan*/  reg_atomic_mutex; int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int EINVAL ; 
 int ETIMEDOUT ; 
 int FIELD_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int FIELD_PREP (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MT7601U_STATE_REMOVED ; 
 int /*<<< orphan*/  MT7601U_STATE_WLAN_RUNNING ; 
 int /*<<< orphan*/  MT_BBP_CSR_CFG ; 
 int MT_BBP_CSR_CFG_BUSY ; 
 int MT_BBP_CSR_CFG_READ ; 
 int /*<<< orphan*/  MT_BBP_CSR_CFG_REG_NUM ; 
 int MT_BBP_CSR_CFG_RW_MODE ; 
 int /*<<< orphan*/  MT_BBP_CSR_CFG_VAL ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  mt7601u_rr (struct mt7601u_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mt7601u_wr (struct mt7601u_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mt76_poll (struct mt7601u_dev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_bbp_read (struct mt7601u_dev*,int,int) ; 

__attribute__((used)) static int mt7601u_bbp_rr(struct mt7601u_dev *dev, u8 offset)
{
	u32 val;
	int ret = -ETIMEDOUT;

	if (WARN_ON(!test_bit(MT7601U_STATE_WLAN_RUNNING, &dev->state)))
		return -EINVAL;
	if (test_bit(MT7601U_STATE_REMOVED, &dev->state))
		return 0xff;

	mutex_lock(&dev->reg_atomic_mutex);

	if (!mt76_poll(dev, MT_BBP_CSR_CFG, MT_BBP_CSR_CFG_BUSY, 0, 1000))
		goto out;

	mt7601u_wr(dev, MT_BBP_CSR_CFG,
		   FIELD_PREP(MT_BBP_CSR_CFG_REG_NUM, offset) |
		   MT_BBP_CSR_CFG_RW_MODE | MT_BBP_CSR_CFG_BUSY |
		   MT_BBP_CSR_CFG_READ);

	if (!mt76_poll(dev, MT_BBP_CSR_CFG, MT_BBP_CSR_CFG_BUSY, 0, 1000))
		goto out;

	val = mt7601u_rr(dev, MT_BBP_CSR_CFG);
	if (FIELD_GET(MT_BBP_CSR_CFG_REG_NUM, val) == offset) {
		ret = FIELD_GET(MT_BBP_CSR_CFG_VAL, val);
		trace_bbp_read(dev, offset, ret);
	}
out:
	mutex_unlock(&dev->reg_atomic_mutex);

	if (ret < 0)
		dev_err(dev->dev, "Error: BBP read %02hhx failed:%d!!\n",
			offset, ret);

	return ret;
}