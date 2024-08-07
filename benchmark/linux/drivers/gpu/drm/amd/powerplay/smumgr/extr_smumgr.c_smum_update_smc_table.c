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
typedef  int /*<<< orphan*/  uint32_t ;
struct pp_hwmgr {TYPE_1__* smumgr_funcs; } ;
struct TYPE_2__ {int (* update_smc_table ) (struct pp_hwmgr*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 

int smum_update_smc_table(struct pp_hwmgr *hwmgr, uint32_t type)
{

	if (NULL != hwmgr->smumgr_funcs->update_smc_table)
		return hwmgr->smumgr_funcs->update_smc_table(hwmgr, type);

	return 0;
}