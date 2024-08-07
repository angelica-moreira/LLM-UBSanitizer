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
typedef  int /*<<< orphan*/  u32 ;
struct isci_port {TYPE_1__* port_task_scheduler_registers; } ;
struct TYPE_2__ {int /*<<< orphan*/  control; } ;

/* Variables and functions */
 int /*<<< orphan*/  SCU_PTSxCR_GEN_BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SUSPEND ; 
 int /*<<< orphan*/  readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sci_port_suspend_port_task_scheduler(struct isci_port *iport)
{
	u32 pts_control_value;

	pts_control_value = readl(&iport->port_task_scheduler_registers->control);
	pts_control_value |= SCU_PTSxCR_GEN_BIT(SUSPEND);
	writel(pts_control_value, &iport->port_task_scheduler_registers->control);
}