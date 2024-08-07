#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  res_q; } ;
struct TYPE_5__ {TYPE_1__ mcu; } ;
struct TYPE_6__ {TYPE_2__ mmio; } ;
struct mt7615_dev {TYPE_3__ mt76; } ;

/* Variables and functions */
 int /*<<< orphan*/  MT_CFG_LPCR_HOST ; 
 int /*<<< orphan*/  MT_CFG_LPCR_HOST_FW_OWN ; 
 int /*<<< orphan*/  __mt76_mcu_restart (TYPE_3__*) ; 
 int /*<<< orphan*/  mt76_wr (struct mt7615_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_queue_purge (int /*<<< orphan*/ *) ; 

void mt7615_mcu_exit(struct mt7615_dev *dev)
{
	__mt76_mcu_restart(&dev->mt76);
	mt76_wr(dev, MT_CFG_LPCR_HOST, MT_CFG_LPCR_HOST_FW_OWN);
	skb_queue_purge(&dev->mt76.mmio.mcu.res_q);
}