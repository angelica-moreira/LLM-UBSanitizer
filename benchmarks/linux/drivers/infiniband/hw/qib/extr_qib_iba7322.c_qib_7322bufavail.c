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
struct qib_devdata {int flags; int /*<<< orphan*/ * int_counter; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int QIB_BADINTR ; 
 int QIB_INITTED ; 
 int /*<<< orphan*/  QIB_I_SPIOBUFAVAIL ; 
 int QIB_PRESENT ; 
 int /*<<< orphan*/  kr_intclear ; 
 int /*<<< orphan*/  qib_ib_piobufavail (struct qib_devdata*) ; 
 int /*<<< orphan*/  qib_wantpiobuf_7322_intr (struct qib_devdata*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qib_write_kreg (struct qib_devdata*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  this_cpu_inc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t qib_7322bufavail(int irq, void *data)
{
	struct qib_devdata *dd = data;

	if ((dd->flags & (QIB_PRESENT | QIB_BADINTR)) != QIB_PRESENT)
		/*
		 * This return value is not great, but we do not want the
		 * interrupt core code to remove our interrupt handler
		 * because we don't appear to be handling an interrupt
		 * during a chip reset.
		 */
		return IRQ_HANDLED;

	this_cpu_inc(*dd->int_counter);

	/* Clear the interrupt bit we expect to be set. */
	qib_write_kreg(dd, kr_intclear, QIB_I_SPIOBUFAVAIL);

	/* qib_ib_piobufavail() will clear the want PIO interrupt if needed */
	if (dd->flags & QIB_INITTED)
		qib_ib_piobufavail(dd);
	else
		qib_wantpiobuf_7322_intr(dd, 0);

	return IRQ_HANDLED;
}