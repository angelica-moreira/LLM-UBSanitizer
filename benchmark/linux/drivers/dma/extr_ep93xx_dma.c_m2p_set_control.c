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
struct ep93xx_dma_chan {scalar_t__ regs; } ;

/* Variables and functions */
 scalar_t__ M2P_CONTROL ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void m2p_set_control(struct ep93xx_dma_chan *edmac, u32 control)
{
	writel(control, edmac->regs + M2P_CONTROL);
	/*
	 * EP93xx User's Guide states that we must perform a dummy read after
	 * write to the control register.
	 */
	readl(edmac->regs + M2P_CONTROL);
}