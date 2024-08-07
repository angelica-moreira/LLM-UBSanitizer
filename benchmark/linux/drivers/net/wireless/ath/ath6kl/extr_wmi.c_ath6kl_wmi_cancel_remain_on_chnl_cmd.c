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
typedef  int /*<<< orphan*/  u8 ;
struct wmi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH6KL_DBG_WMI ; 
 int /*<<< orphan*/  WMI_CANCEL_REMAIN_ON_CHNL_CMDID ; 
 int /*<<< orphan*/  ath6kl_dbg (int /*<<< orphan*/ ,char*) ; 
 int ath6kl_wmi_simple_cmd (struct wmi*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int ath6kl_wmi_cancel_remain_on_chnl_cmd(struct wmi *wmi, u8 if_idx)
{
	ath6kl_dbg(ATH6KL_DBG_WMI, "cancel_remain_on_chnl_cmd\n");
	return ath6kl_wmi_simple_cmd(wmi, if_idx,
				     WMI_CANCEL_REMAIN_ON_CHNL_CMDID);
}