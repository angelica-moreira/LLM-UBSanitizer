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
typedef  int u32 ;
struct xhci_hcd {TYPE_1__* op_regs; } ;
struct TYPE_2__ {int /*<<< orphan*/  command; int /*<<< orphan*/  status; } ;

/* Variables and functions */
 int CMD_RUN ; 
 int STS_HALT ; 
 int XHCI_IRQS ; 
 int readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ *) ; 

void xhci_quiesce(struct xhci_hcd *xhci)
{
	u32 halted;
	u32 cmd;
	u32 mask;

	mask = ~(XHCI_IRQS);
	halted = readl(&xhci->op_regs->status) & STS_HALT;
	if (!halted)
		mask &= ~CMD_RUN;

	cmd = readl(&xhci->op_regs->command);
	cmd &= mask;
	writel(cmd, &xhci->op_regs->command);
}