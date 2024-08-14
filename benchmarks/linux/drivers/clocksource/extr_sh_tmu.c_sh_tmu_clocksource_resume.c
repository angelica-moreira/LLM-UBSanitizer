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
struct sh_tmu_channel {TYPE_2__* tmu; int /*<<< orphan*/  enable_count; int /*<<< orphan*/  cs_enabled; } ;
struct clocksource {int dummy; } ;
struct TYPE_4__ {TYPE_1__* pdev; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  __sh_tmu_enable (struct sh_tmu_channel*) ; 
 struct sh_tmu_channel* cs_to_sh_tmu (struct clocksource*) ; 
 int /*<<< orphan*/  pm_genpd_syscore_poweron (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sh_tmu_clocksource_resume(struct clocksource *cs)
{
	struct sh_tmu_channel *ch = cs_to_sh_tmu(cs);

	if (!ch->cs_enabled)
		return;

	if (ch->enable_count++ == 0) {
		pm_genpd_syscore_poweron(&ch->tmu->pdev->dev);
		__sh_tmu_enable(ch);
	}
}