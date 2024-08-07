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
struct xmit_priv {int tx_bytes; } ;
struct TYPE_4__ {struct sta_info* psta; } ;
struct xmit_frame {int frame_tag; scalar_t__ agg_num; TYPE_2__ attrib; } ;
struct stainfo_stats {int tx_bytes; int /*<<< orphan*/  tx_pkts; } ;
struct sta_info {struct stainfo_stats sta_stats; } ;
struct TYPE_3__ {int /*<<< orphan*/  NumTxOkInPeriod; } ;
struct mlme_priv {TYPE_1__ LinkDetectInfo; } ;
struct adapter {struct mlme_priv mlmepriv; struct xmit_priv xmitpriv; } ;

/* Variables and functions */
 int DATA_FRAMETAG ; 

void rtw_count_tx_stats(struct adapter *padapter, struct xmit_frame *pxmitframe, int sz)
{
	struct sta_info *psta = NULL;
	struct stainfo_stats *pstats = NULL;
	struct xmit_priv	*pxmitpriv = &padapter->xmitpriv;
	struct mlme_priv	*pmlmepriv = &padapter->mlmepriv;

	if ((pxmitframe->frame_tag & 0x0f) == DATA_FRAMETAG) {
		pxmitpriv->tx_bytes += sz;
		pmlmepriv->LinkDetectInfo.NumTxOkInPeriod += pxmitframe->agg_num;

		psta = pxmitframe->attrib.psta;
		if (psta) {
			pstats = &psta->sta_stats;
			pstats->tx_pkts += pxmitframe->agg_num;
			pstats->tx_bytes += sz;
		}
	}
}