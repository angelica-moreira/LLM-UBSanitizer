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
struct mt7601u_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MT_MAC_SYS_CTRL ; 
 int MT_MAC_SYS_CTRL_RESET_BBP ; 
 int MT_MAC_SYS_CTRL_RESET_CSR ; 
 int /*<<< orphan*/  MT_USB_DMA_CFG ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mt7601u_wr (struct mt7601u_dev*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void mt7601u_reset_csr_bbp(struct mt7601u_dev *dev)
{
	mt7601u_wr(dev, MT_MAC_SYS_CTRL, (MT_MAC_SYS_CTRL_RESET_CSR |
					  MT_MAC_SYS_CTRL_RESET_BBP));
	mt7601u_wr(dev, MT_USB_DMA_CFG, 0);
	msleep(1);
	mt7601u_wr(dev, MT_MAC_SYS_CTRL, 0);
}