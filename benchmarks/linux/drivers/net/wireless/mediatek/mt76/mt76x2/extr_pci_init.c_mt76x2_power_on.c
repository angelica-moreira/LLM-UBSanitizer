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
struct mt76x02_dev {int dummy; } ;

/* Variables and functions */
 int BIT (int) ; 
 int MT_WLAN_MTC_CTRL ; 
 int MT_WLAN_MTC_CTRL_MTCMOS_PWR_UP ; 
 int MT_WLAN_MTC_CTRL_PWR_ACK ; 
 int MT_WLAN_MTC_CTRL_PWR_ACK_S ; 
 int MT_WLAN_MTC_CTRL_STATE_UP ; 
 int /*<<< orphan*/  mt76_clear (struct mt76x02_dev*,int,int) ; 
 int /*<<< orphan*/  mt76_poll (struct mt76x02_dev*,int,int,int,int) ; 
 int /*<<< orphan*/  mt76_set (struct mt76x02_dev*,int,int) ; 
 int /*<<< orphan*/  mt76x2_power_on_rf (struct mt76x02_dev*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void
mt76x2_power_on(struct mt76x02_dev *dev)
{
	u32 val;

	/* Turn on WL MTCMOS */
	mt76_set(dev, MT_WLAN_MTC_CTRL, MT_WLAN_MTC_CTRL_MTCMOS_PWR_UP);

	val = MT_WLAN_MTC_CTRL_STATE_UP |
	      MT_WLAN_MTC_CTRL_PWR_ACK |
	      MT_WLAN_MTC_CTRL_PWR_ACK_S;

	mt76_poll(dev, MT_WLAN_MTC_CTRL, val, val, 1000);

	mt76_clear(dev, MT_WLAN_MTC_CTRL, 0x7f << 16);
	udelay(10);

	mt76_clear(dev, MT_WLAN_MTC_CTRL, 0xf << 24);
	udelay(10);

	mt76_set(dev, MT_WLAN_MTC_CTRL, 0xf << 24);
	mt76_clear(dev, MT_WLAN_MTC_CTRL, 0xfff);

	/* Turn on AD/DA power down */
	mt76_clear(dev, 0x11204, BIT(3));

	/* WLAN function enable */
	mt76_set(dev, 0x10080, BIT(0));

	/* Release BBP software reset */
	mt76_clear(dev, 0x10064, BIT(18));

	mt76x2_power_on_rf(dev, 0);
	mt76x2_power_on_rf(dev, 1);
}