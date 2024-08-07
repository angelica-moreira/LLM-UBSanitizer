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
struct dwc3_omap {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  dwc3_omap_enable_irqs (struct dwc3_omap*) ; 
 int /*<<< orphan*/  dwc3_omap_read_irq0_status (struct dwc3_omap*) ; 
 int /*<<< orphan*/  dwc3_omap_read_irqmisc_status (struct dwc3_omap*) ; 
 int /*<<< orphan*/  dwc3_omap_write_irq0_status (struct dwc3_omap*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dwc3_omap_write_irqmisc_status (struct dwc3_omap*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t dwc3_omap_interrupt_thread(int irq, void *_omap)
{
	struct dwc3_omap	*omap = _omap;
	u32			reg;

	/* clear irq status flags */
	reg = dwc3_omap_read_irqmisc_status(omap);
	dwc3_omap_write_irqmisc_status(omap, reg);

	reg = dwc3_omap_read_irq0_status(omap);
	dwc3_omap_write_irq0_status(omap, reg);

	/* unmask irqs */
	dwc3_omap_enable_irqs(omap);

	return IRQ_HANDLED;
}