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
struct smc_link_group {int /*<<< orphan*/  free_work; } ;

/* Variables and functions */
 int /*<<< orphan*/  SMC_LGR_FREE_DELAY_FAST ; 
 int /*<<< orphan*/  mod_delayed_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  system_wq ; 

void smc_lgr_schedule_free_work_fast(struct smc_link_group *lgr)
{
	mod_delayed_work(system_wq, &lgr->free_work, SMC_LGR_FREE_DELAY_FAST);
}