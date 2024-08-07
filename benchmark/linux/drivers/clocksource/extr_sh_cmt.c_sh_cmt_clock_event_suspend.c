#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sh_cmt_channel {TYPE_2__* cmt; } ;
struct clock_event_device {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  clk; TYPE_1__* pdev; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 struct sh_cmt_channel* ced_to_sh_cmt (struct clock_event_device*) ; 
 int /*<<< orphan*/  clk_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_genpd_syscore_poweroff (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sh_cmt_clock_event_suspend(struct clock_event_device *ced)
{
	struct sh_cmt_channel *ch = ced_to_sh_cmt(ced);

	pm_genpd_syscore_poweroff(&ch->cmt->pdev->dev);
	clk_unprepare(ch->cmt->clk);
}