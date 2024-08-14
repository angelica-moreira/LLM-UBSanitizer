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

/* Variables and functions */
 int MCF_BUSCLK ; 
 int /*<<< orphan*/  MCF_GPT_GCIR0 ; 
 unsigned int MCF_GPT_GCIR_CNT (int) ; 
 unsigned int MCF_GPT_GCIR_PRE (int) ; 
 int /*<<< orphan*/  MCF_GPT_GMS0 ; 
 unsigned int MCF_GPT_GMS_CE ; 
 unsigned int MCF_GPT_GMS_GPIO_MASK ; 
 unsigned int MCF_GPT_GMS_OCPW (int) ; 
 unsigned int MCF_GPT_GMS_OD ; 
 unsigned int MCF_GPT_GMS_TMS_GPIO ; 
 unsigned int MCF_GPT_GMS_WDEN ; 
 unsigned int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,int /*<<< orphan*/ ) ; 
 int heartbeat ; 

__attribute__((used)) static void wdt_enable(void)
{
	unsigned int gms0;

	/* preserve GPIO usage, if any */
	gms0 = __raw_readl(MCF_GPT_GMS0);
	if (gms0 & MCF_GPT_GMS_TMS_GPIO)
		gms0 &= (MCF_GPT_GMS_TMS_GPIO | MCF_GPT_GMS_GPIO_MASK
							| MCF_GPT_GMS_OD);
	else
		gms0 = MCF_GPT_GMS_TMS_GPIO | MCF_GPT_GMS_OD;
	__raw_writel(gms0, MCF_GPT_GMS0);
	__raw_writel(MCF_GPT_GCIR_PRE(heartbeat*(MCF_BUSCLK/0xffff)) |
			MCF_GPT_GCIR_CNT(0xffff), MCF_GPT_GCIR0);
	gms0 |= MCF_GPT_GMS_OCPW(0xA5) | MCF_GPT_GMS_WDEN | MCF_GPT_GMS_CE;
	__raw_writel(gms0, MCF_GPT_GMS0);
}