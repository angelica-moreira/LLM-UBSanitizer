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
typedef  scalar_t__ u32 ;
struct bcm63xx_udc {scalar_t__ usbd_regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcm_writel (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline void usbd_writel(struct bcm63xx_udc *udc, u32 val, u32 off)
{
	bcm_writel(val, udc->usbd_regs + off);
}