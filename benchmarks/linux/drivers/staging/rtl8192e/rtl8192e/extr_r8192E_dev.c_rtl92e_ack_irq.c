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
struct net_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ISR ; 
 int /*<<< orphan*/  rtl92e_readl (struct net_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtl92e_writel (struct net_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void rtl92e_ack_irq(struct net_device *dev, u32 *p_inta, u32 *p_intb)
{
	*p_inta = rtl92e_readl(dev, ISR);
	rtl92e_writel(dev, ISR, *p_inta);
}