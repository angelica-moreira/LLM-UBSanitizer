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
struct clk {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  EP93XX_SYSCON_PWRCNT ; 
 int EP93XX_SYSCON_PWRCNT_UARTBAUD ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 unsigned long clk_get_rate (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long get_uart_rate(struct clk *clk)
{
	unsigned long rate = clk_get_rate(clk->parent);
	u32 value;

	value = __raw_readl(EP93XX_SYSCON_PWRCNT);
	if (value & EP93XX_SYSCON_PWRCNT_UARTBAUD)
		return rate;
	else
		return rate / 2;
}