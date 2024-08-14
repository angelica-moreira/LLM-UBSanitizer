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
struct smu8_hwmgr {int acp_boot_level; } ;
struct pp_hwmgr {struct smu8_hwmgr* backend; } ;

/* Variables and functions */

__attribute__((used)) static void smu8_reset_acp_boot_level(struct pp_hwmgr *hwmgr)
{
	struct smu8_hwmgr *data = hwmgr->backend;

	data->acp_boot_level = 0xff;
}