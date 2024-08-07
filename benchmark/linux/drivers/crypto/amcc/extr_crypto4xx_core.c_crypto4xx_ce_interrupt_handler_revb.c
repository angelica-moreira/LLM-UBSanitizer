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
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int PPC4XX_INTERRUPT_CLR ; 
 int PPC4XX_TMO_ERR_INT ; 
 int /*<<< orphan*/  crypto4xx_interrupt_handler (int,void*,int) ; 

__attribute__((used)) static irqreturn_t crypto4xx_ce_interrupt_handler_revb(int irq, void *data)
{
	return crypto4xx_interrupt_handler(irq, data, PPC4XX_INTERRUPT_CLR |
		PPC4XX_TMO_ERR_INT);
}