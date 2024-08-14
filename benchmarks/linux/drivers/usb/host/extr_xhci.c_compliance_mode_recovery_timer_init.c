#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ expires; } ;
struct xhci_hcd {TYPE_1__ comp_mode_recovery_timer; scalar_t__ port_status_u0; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMP_MODE_RCVRY_MSECS ; 
 int /*<<< orphan*/  add_timer (TYPE_1__*) ; 
 int /*<<< orphan*/  compliance_mode_recovery ; 
 scalar_t__ jiffies ; 
 scalar_t__ msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  timer_setup (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_xhci_dbg_quirks ; 
 int /*<<< orphan*/  xhci_dbg_trace (struct xhci_hcd*,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void compliance_mode_recovery_timer_init(struct xhci_hcd *xhci)
{
	xhci->port_status_u0 = 0;
	timer_setup(&xhci->comp_mode_recovery_timer, compliance_mode_recovery,
		    0);
	xhci->comp_mode_recovery_timer.expires = jiffies +
			msecs_to_jiffies(COMP_MODE_RCVRY_MSECS);

	add_timer(&xhci->comp_mode_recovery_timer);
	xhci_dbg_trace(xhci, trace_xhci_dbg_quirks,
			"Compliance mode recovery timer initialized");
}