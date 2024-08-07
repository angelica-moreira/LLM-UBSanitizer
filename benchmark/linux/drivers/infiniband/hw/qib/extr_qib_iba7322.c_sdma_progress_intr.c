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
struct qib_pportdata {scalar_t__ hw_pidx; struct qib_devdata* dd; } ;
struct qib_devdata {int flags; int /*<<< orphan*/ * int_counter; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  INT_MASK_P (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int QIB_BADINTR ; 
 int QIB_PRESENT ; 
 int /*<<< orphan*/  SDmaProgress ; 
 int /*<<< orphan*/  kr_intclear ; 
 int /*<<< orphan*/  qib_sdma_intr (struct qib_pportdata*) ; 
 int /*<<< orphan*/  qib_write_kreg (struct qib_devdata*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  this_cpu_inc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t sdma_progress_intr(int irq, void *data)
{
	struct qib_pportdata *ppd = data;
	struct qib_devdata *dd = ppd->dd;

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
	qib_write_kreg(dd, kr_intclear, ppd->hw_pidx ?
		       INT_MASK_P(SDmaProgress, 1) :
		       INT_MASK_P(SDmaProgress, 0));
	qib_sdma_intr(ppd);

	return IRQ_HANDLED;
}