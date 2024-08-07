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
struct musb {int /*<<< orphan*/  mregs; } ;

/* Variables and functions */
 int /*<<< orphan*/  MUSB_DEVCTL ; 
 int /*<<< orphan*/  musb_disable_interrupts (struct musb*) ; 
 int /*<<< orphan*/  musb_platform_disable (struct musb*) ; 
 int /*<<< orphan*/  musb_platform_try_idle (struct musb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  musb_writeb (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void musb_stop(struct musb *musb)
{
	/* stop IRQs, timers, ... */
	musb_platform_disable(musb);
	musb_disable_interrupts(musb);
	musb_writeb(musb->mregs, MUSB_DEVCTL, 0);

	/* FIXME
	 *  - mark host and/or peripheral drivers unusable/inactive
	 *  - disable DMA (and enable it in HdrcStart)
	 *  - make sure we can musb_start() after musb_stop(); with
	 *    OTG mode, gadget driver module rmmod/modprobe cycles that
	 *  - ...
	 */
	musb_platform_try_idle(musb, 0);
}