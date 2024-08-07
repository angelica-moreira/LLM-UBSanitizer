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
struct pic32_rtc_dev {int alarm_clk_enabled; int /*<<< orphan*/  alarm_lock; int /*<<< orphan*/  clk; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void pic32_rtc_alarm_clk_enable(struct pic32_rtc_dev *pdata,
				       bool enable)
{
	unsigned long flags;

	spin_lock_irqsave(&pdata->alarm_lock, flags);
	if (enable) {
		if (!pdata->alarm_clk_enabled) {
			clk_enable(pdata->clk);
			pdata->alarm_clk_enabled = true;
		}
	} else {
		if (pdata->alarm_clk_enabled) {
			clk_disable(pdata->clk);
			pdata->alarm_clk_enabled = false;
		}
	}
	spin_unlock_irqrestore(&pdata->alarm_lock, flags);
}