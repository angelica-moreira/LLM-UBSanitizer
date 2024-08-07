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
struct TYPE_2__ {int /*<<< orphan*/  heartbeat; } ;
struct bfa_ioc {int /*<<< orphan*/  hb_timer; TYPE_1__ ioc_regs; int /*<<< orphan*/  hb_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_IOC_HB_TOV ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bfa_ioc_hb_monitor(struct bfa_ioc *ioc)
{
	ioc->hb_count = readl(ioc->ioc_regs.heartbeat);
	mod_timer(&ioc->hb_timer, jiffies +
		msecs_to_jiffies(BFA_IOC_HB_TOV));
}