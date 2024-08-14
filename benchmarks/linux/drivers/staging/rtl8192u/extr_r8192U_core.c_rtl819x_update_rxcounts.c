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
typedef  size_t u8 ;
typedef  scalar_t__ u32 ;
typedef  size_t u16 ;
struct r8192_priv {TYPE_2__* ieee80211; } ;
struct TYPE_3__ {size_t SlotNum; scalar_t__* RxDataNum; scalar_t__* RxBcnNum; scalar_t__ NumRecvDataInPeriod; scalar_t__ NumRecvBcnInPeriod; int /*<<< orphan*/  SlotIndex; } ;
struct TYPE_4__ {TYPE_1__ LinkDetectInfo; } ;

/* Variables and functions */

__attribute__((used)) static void rtl819x_update_rxcounts(struct r8192_priv *priv, u32 *TotalRxBcnNum,
			     u32 *TotalRxDataNum)
{
	u16			SlotIndex;
	u8			i;

	*TotalRxBcnNum = 0;
	*TotalRxDataNum = 0;

	SlotIndex = (priv->ieee80211->LinkDetectInfo.SlotIndex++) %
		    (priv->ieee80211->LinkDetectInfo.SlotNum);
	priv->ieee80211->LinkDetectInfo.RxBcnNum[SlotIndex] =
		priv->ieee80211->LinkDetectInfo.NumRecvBcnInPeriod;
	priv->ieee80211->LinkDetectInfo.RxDataNum[SlotIndex] =
		priv->ieee80211->LinkDetectInfo.NumRecvDataInPeriod;
	for (i = 0; i < priv->ieee80211->LinkDetectInfo.SlotNum; i++) {
		*TotalRxBcnNum += priv->ieee80211->LinkDetectInfo.RxBcnNum[i];
		*TotalRxDataNum += priv->ieee80211->LinkDetectInfo.RxDataNum[i];
	}
}