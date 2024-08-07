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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct sta_priv {int dummy; } ;
struct sta_info {int qos_info; int state; int uapsd_bk; int uapsd_vi; int uapsd_vo; int uapsd_be; scalar_t__ sleepq_ac_len; int /*<<< orphan*/  hwaddr; int /*<<< orphan*/  qos_option; } ;
struct rx_pkt_attrib {int priority; int /*<<< orphan*/  src; } ;
struct recv_frame {struct rx_pkt_attrib attrib; } ;
struct adapter {struct sta_priv stapriv; } ;

/* Variables and functions */
 int BIT (int) ; 
 int WIFI_SLEEP_STATE ; 
 int /*<<< orphan*/  issue_qos_nulldata (struct adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct sta_info* rtw_get_stainfo (struct sta_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xmit_delivery_enabled_frames (struct adapter*,struct sta_info*) ; 

__attribute__((used)) static void process_wmmps_data(struct adapter *padapter,
			       struct recv_frame *precv_frame)
{
#ifdef CONFIG_88EU_AP_MODE
	struct rx_pkt_attrib *pattrib = &precv_frame->attrib;
	struct sta_priv *pstapriv = &padapter->stapriv;
	struct sta_info *psta = NULL;

	psta = rtw_get_stainfo(pstapriv, pattrib->src);

	if (!psta)
		return;

	if (!psta->qos_option)
		return;

	if (!(psta->qos_info&0xf))
		return;

	if (psta->state&WIFI_SLEEP_STATE) {
		u8 wmmps_ac = 0;

		switch (pattrib->priority) {
		case 1:
		case 2:
			wmmps_ac = psta->uapsd_bk&BIT(1);
			break;
		case 4:
		case 5:
			wmmps_ac = psta->uapsd_vi&BIT(1);
			break;
		case 6:
		case 7:
			wmmps_ac = psta->uapsd_vo&BIT(1);
			break;
		case 0:
		case 3:
		default:
			wmmps_ac = psta->uapsd_be&BIT(1);
			break;
		}

		if (wmmps_ac) {
			if (psta->sleepq_ac_len > 0) {
				/* process received triggered frame */
				xmit_delivery_enabled_frames(padapter, psta);
			} else {
				/* issue one qos null frame with More data bit = 0 and the EOSP bit set (= 1) */
				issue_qos_nulldata(padapter, psta->hwaddr, (u16)pattrib->priority, 0, 0);
			}
		}
	}

#endif
}