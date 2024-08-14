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
typedef  int u32 ;
struct lpc32xx_udc {int realized_eps; int /*<<< orphan*/  udp_baseaddr; } ;

/* Variables and functions */
 int /*<<< orphan*/  USBD_REEP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void udc_unrealize_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
	udc->realized_eps &= ~(1 << hwep);
	writel(udc->realized_eps, USBD_REEP(udc->udp_baseaddr));
}