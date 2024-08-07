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
typedef  int /*<<< orphan*/  u32 ;
struct rt2x00_dev {int /*<<< orphan*/  tbtt_tasklet; } ;
struct data_queue {int qid; struct rt2x00_dev* rt2x00dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  CSR14 ; 
 int /*<<< orphan*/  CSR14_BEACON_GEN ; 
 int /*<<< orphan*/  CSR14_TBCN ; 
 int /*<<< orphan*/  CSR14_TSF_COUNT ; 
#define  QID_AC_VI 132 
#define  QID_AC_VO 131 
#define  QID_ATIM 130 
#define  QID_BEACON 129 
#define  QID_RX 128 
 int /*<<< orphan*/  RXCSR0 ; 
 int /*<<< orphan*/  RXCSR0_DISABLE_RX ; 
 int /*<<< orphan*/  TXCSR0 ; 
 int /*<<< orphan*/  TXCSR0_ABORT ; 
 int /*<<< orphan*/  rt2x00_set_field32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rt2x00mmio_register_read (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00mmio_register_write (struct rt2x00_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tasklet_kill (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void rt2500pci_stop_queue(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	u32 reg;

	switch (queue->qid) {
	case QID_AC_VO:
	case QID_AC_VI:
	case QID_ATIM:
		reg = rt2x00mmio_register_read(rt2x00dev, TXCSR0);
		rt2x00_set_field32(&reg, TXCSR0_ABORT, 1);
		rt2x00mmio_register_write(rt2x00dev, TXCSR0, reg);
		break;
	case QID_RX:
		reg = rt2x00mmio_register_read(rt2x00dev, RXCSR0);
		rt2x00_set_field32(&reg, RXCSR0_DISABLE_RX, 1);
		rt2x00mmio_register_write(rt2x00dev, RXCSR0, reg);
		break;
	case QID_BEACON:
		reg = rt2x00mmio_register_read(rt2x00dev, CSR14);
		rt2x00_set_field32(&reg, CSR14_TSF_COUNT, 0);
		rt2x00_set_field32(&reg, CSR14_TBCN, 0);
		rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 0);
		rt2x00mmio_register_write(rt2x00dev, CSR14, reg);

		/*
		 * Wait for possibly running tbtt tasklets.
		 */
		tasklet_kill(&rt2x00dev->tbtt_tasklet);
		break;
	default:
		break;
	}
}