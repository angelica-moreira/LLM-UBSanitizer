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
struct TYPE_2__ {int queue; int /*<<< orphan*/  running; int /*<<< orphan*/  timer; int /*<<< orphan*/  lock; int /*<<< orphan*/  base_reg; int /*<<< orphan*/  sb_pdev; } ;

/* Variables and functions */
 int RDC_CLS_TMR ; 
 int RDC_WDT_CNT ; 
 int RDC_WDT_EN ; 
 scalar_t__ RDC_WDT_INTERVAL ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  pci_write_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 TYPE_1__ rdc321x_wdt_device ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void rdc321x_wdt_start(void)
{
	unsigned long flags;

	if (!rdc321x_wdt_device.queue) {
		rdc321x_wdt_device.queue = 1;

		/* Clear the timer */
		spin_lock_irqsave(&rdc321x_wdt_device.lock, flags);
		pci_write_config_dword(rdc321x_wdt_device.sb_pdev,
				rdc321x_wdt_device.base_reg, RDC_CLS_TMR);

		/* Enable watchdog and set the timeout to 81.92 us */
		pci_write_config_dword(rdc321x_wdt_device.sb_pdev,
					rdc321x_wdt_device.base_reg,
					RDC_WDT_EN | RDC_WDT_CNT);
		spin_unlock_irqrestore(&rdc321x_wdt_device.lock, flags);

		mod_timer(&rdc321x_wdt_device.timer,
				jiffies + RDC_WDT_INTERVAL);
	}

	/* if process dies, counter is not decremented */
	rdc321x_wdt_device.running++;
}