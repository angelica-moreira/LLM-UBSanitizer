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
struct wmi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WMI_GET_ROAM_TBL_CMDID ; 
 int ath6kl_wmi_simple_cmd (struct wmi*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int ath6kl_wmi_get_roam_tbl_cmd(struct wmi *wmi)
{
	return ath6kl_wmi_simple_cmd(wmi, 0, WMI_GET_ROAM_TBL_CMDID);
}