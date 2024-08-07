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
typedef  scalar_t__ u32 ;
struct cdns3_device {scalar_t__ selected_ep; TYPE_1__* regs; } ;
struct TYPE_2__ {int /*<<< orphan*/  ep_sel; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel (scalar_t__,int /*<<< orphan*/ *) ; 

void cdns3_select_ep(struct cdns3_device *priv_dev, u32 ep)
{
	if (priv_dev->selected_ep == ep)
		return;

	priv_dev->selected_ep = ep;
	writel(ep, &priv_dev->regs->ep_sel);
}