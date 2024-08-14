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
typedef  int /*<<< orphan*/  u8 ;
struct regulatory_request {int /*<<< orphan*/  initiator; } ;
struct mlme_ext_priv {int /*<<< orphan*/  channel_list; int /*<<< orphan*/  max_chan_nums; int /*<<< orphan*/  channel_set; } ;
struct adapter {TYPE_1__* rtw_wdev; struct mlme_ext_priv mlmeextpriv; } ;
struct SetChannelPlan_param {int /*<<< orphan*/  channel_plan; } ;
struct TYPE_2__ {scalar_t__ wiphy; } ;

/* Variables and functions */
 int /*<<< orphan*/  H2C_PARAMETERS_ERROR ; 
 int /*<<< orphan*/  H2C_SUCCESS ; 
 int /*<<< orphan*/  NL80211_REGDOM_SET_BY_DRIVER ; 
 int /*<<< orphan*/  init_channel_list (struct adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  init_channel_set (struct adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtw_reg_notifier (scalar_t__,struct regulatory_request*) ; 

u8 set_chplan_hdl(struct adapter *padapter, unsigned char *pbuf)
{
	struct SetChannelPlan_param *setChannelPlan_param;
	struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;

	if (!pbuf)
		return H2C_PARAMETERS_ERROR;

	setChannelPlan_param = (struct SetChannelPlan_param *)pbuf;

	pmlmeext->max_chan_nums = init_channel_set(padapter, setChannelPlan_param->channel_plan, pmlmeext->channel_set);
	init_channel_list(padapter, pmlmeext->channel_set, pmlmeext->max_chan_nums, &pmlmeext->channel_list);

	if ((padapter->rtw_wdev != NULL) && (padapter->rtw_wdev->wiphy)) {
		struct regulatory_request request;
		request.initiator = NL80211_REGDOM_SET_BY_DRIVER;
		rtw_reg_notifier(padapter->rtw_wdev->wiphy, &request);
	}

	return	H2C_SUCCESS;
}