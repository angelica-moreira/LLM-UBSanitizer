#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct dtl1_info {unsigned char ri_latch; int /*<<< orphan*/  lock; int /*<<< orphan*/  tx_state; TYPE_2__* p_dev; int /*<<< orphan*/  hdev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_4__ {TYPE_1__** resource; } ;
struct TYPE_3__ {unsigned int start; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_ERR (char*,...) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ UART_IIR ; 
 int UART_IIR_ID ; 
#define  UART_IIR_RDI 130 
#define  UART_IIR_RLSI 129 
#define  UART_IIR_THRI 128 
 scalar_t__ UART_LSR ; 
 int UART_LSR_THRE ; 
 scalar_t__ UART_MSR ; 
 unsigned char UART_MSR_RI ; 
 int /*<<< orphan*/  XMIT_WAITING ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dtl1_receive (struct dtl1_info*) ; 
 int /*<<< orphan*/  dtl1_write_wakeup (struct dtl1_info*) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t dtl1_interrupt(int irq, void *dev_inst)
{
	struct dtl1_info *info = dev_inst;
	unsigned int iobase;
	unsigned char msr;
	int boguscount = 0;
	int iir, lsr;
	irqreturn_t r = IRQ_NONE;

	if (!info || !info->hdev)
		/* our irq handler is shared */
		return IRQ_NONE;

	iobase = info->p_dev->resource[0]->start;

	spin_lock(&(info->lock));

	iir = inb(iobase + UART_IIR) & UART_IIR_ID;
	while (iir) {

		r = IRQ_HANDLED;
		/* Clear interrupt */
		lsr = inb(iobase + UART_LSR);

		switch (iir) {
		case UART_IIR_RLSI:
			BT_ERR("RLSI");
			break;
		case UART_IIR_RDI:
			/* Receive interrupt */
			dtl1_receive(info);
			break;
		case UART_IIR_THRI:
			if (lsr & UART_LSR_THRE) {
				/* Transmitter ready for data */
				dtl1_write_wakeup(info);
			}
			break;
		default:
			BT_ERR("Unhandled IIR=%#x", iir);
			break;
		}

		/* Make sure we don't stay here too long */
		if (boguscount++ > 100)
			break;

		iir = inb(iobase + UART_IIR) & UART_IIR_ID;

	}

	msr = inb(iobase + UART_MSR);

	if (info->ri_latch ^ (msr & UART_MSR_RI)) {
		info->ri_latch = msr & UART_MSR_RI;
		clear_bit(XMIT_WAITING, &(info->tx_state));
		dtl1_write_wakeup(info);
		r = IRQ_HANDLED;
	}

	spin_unlock(&(info->lock));

	return r;
}