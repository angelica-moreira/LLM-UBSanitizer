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
struct TYPE_2__ {int /*<<< orphan*/  mac_work; } ;
struct mt76x02_dev {int /*<<< orphan*/  wdt_work; TYPE_1__ mt76; int /*<<< orphan*/  cal_work; } ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_delayed_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mt76x02_mcu_set_radio_state (struct mt76x02_dev*,int) ; 
 int /*<<< orphan*/  mt76x2_mac_stop (struct mt76x02_dev*,int) ; 

void mt76x2_stop_hardware(struct mt76x02_dev *dev)
{
	cancel_delayed_work_sync(&dev->cal_work);
	cancel_delayed_work_sync(&dev->mt76.mac_work);
	cancel_delayed_work_sync(&dev->wdt_work);
	mt76x02_mcu_set_radio_state(dev, false);
	mt76x2_mac_stop(dev, false);
}