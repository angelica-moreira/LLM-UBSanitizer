#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct xmit_priv {int* wmm_para_seq; } ;
struct registry_priv {int acm_method; int wifi_spec; } ;
struct TYPE_5__ {TYPE_1__* ac_param; } ;
struct mlme_ext_info {scalar_t__ WMM_enable; int slotTime; TYPE_2__ WMM_param; } ;
struct mlme_ext_priv {scalar_t__ cur_wireless_mode; struct mlme_ext_info mlmext_info; } ;
struct TYPE_6__ {int acm_mask; } ;
struct adapter {TYPE_3__ mlmepriv; struct registry_priv registrypriv; struct xmit_priv xmitpriv; struct mlme_ext_priv mlmeextpriv; } ;
struct TYPE_4__ {int ACI_AIFSN; int CW; int /*<<< orphan*/  TXOP_limit; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  DBG_88E (char*,int,int,...) ; 
 int /*<<< orphan*/  HW_VAR_ACM_CTRL ; 
 int /*<<< orphan*/  HW_VAR_AC_PARAM_BE ; 
 int /*<<< orphan*/  HW_VAR_AC_PARAM_BK ; 
 int /*<<< orphan*/  HW_VAR_AC_PARAM_VI ; 
 int /*<<< orphan*/  HW_VAR_AC_PARAM_VO ; 
 scalar_t__ WIRELESS_11B ; 
 size_t XMIT_BE_QUEUE ; 
 size_t XMIT_BK_QUEUE ; 
 size_t XMIT_VI_QUEUE ; 
 size_t XMIT_VO_QUEUE ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtw_hal_set_hwreg (struct adapter*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  swap (int,int) ; 

void WMMOnAssocRsp(struct adapter *padapter)
{
	u8 ACI, ACM, AIFS, ECWMin, ECWMax, aSifsTime;
	u8 acm_mask;
	u16 TXOP;
	u32 acParm, i;
	u32 edca[4], inx[4];
	struct mlme_ext_priv *pmlmeext = &padapter->mlmeextpriv;
	struct mlme_ext_info *pmlmeinfo = &pmlmeext->mlmext_info;
	struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
	struct registry_priv *pregpriv = &padapter->registrypriv;

	if (pmlmeinfo->WMM_enable == 0) {
		padapter->mlmepriv.acm_mask = 0;
		return;
	}

	acm_mask = 0;

	if (pmlmeext->cur_wireless_mode == WIRELESS_11B)
		aSifsTime = 10;
	else
		aSifsTime = 16;

	for (i = 0; i < 4; i++) {
		ACI = (pmlmeinfo->WMM_param.ac_param[i].ACI_AIFSN >> 5) & 0x03;
		ACM = (pmlmeinfo->WMM_param.ac_param[i].ACI_AIFSN >> 4) & 0x01;

		/* AIFS = AIFSN * slot time + SIFS - r2t phy delay */
		AIFS = (pmlmeinfo->WMM_param.ac_param[i].ACI_AIFSN & 0x0f) * pmlmeinfo->slotTime + aSifsTime;

		ECWMin = pmlmeinfo->WMM_param.ac_param[i].CW & 0x0f;
		ECWMax = (pmlmeinfo->WMM_param.ac_param[i].CW & 0xf0) >> 4;
		TXOP = le16_to_cpu(pmlmeinfo->WMM_param.ac_param[i].TXOP_limit);

		acParm = AIFS | (ECWMin << 8) | (ECWMax << 12) | (TXOP << 16);

		switch (ACI) {
		case 0x0:
			rtw_hal_set_hwreg(padapter, HW_VAR_AC_PARAM_BE, (u8 *)(&acParm));
			acm_mask |= (ACM ? BIT(1) : 0);
			edca[XMIT_BE_QUEUE] = acParm;
			break;
		case 0x1:
			rtw_hal_set_hwreg(padapter, HW_VAR_AC_PARAM_BK, (u8 *)(&acParm));
			edca[XMIT_BK_QUEUE] = acParm;
			break;
		case 0x2:
			rtw_hal_set_hwreg(padapter, HW_VAR_AC_PARAM_VI, (u8 *)(&acParm));
			acm_mask |= (ACM ? BIT(2) : 0);
			edca[XMIT_VI_QUEUE] = acParm;
			break;
		case 0x3:
			rtw_hal_set_hwreg(padapter, HW_VAR_AC_PARAM_VO, (u8 *)(&acParm));
			acm_mask |= (ACM ? BIT(3) : 0);
			edca[XMIT_VO_QUEUE] = acParm;
			break;
		}

		DBG_88E("WMM(%x): %x, %x\n", ACI, ACM, acParm);
	}

	if (padapter->registrypriv.acm_method == 1)
		rtw_hal_set_hwreg(padapter, HW_VAR_ACM_CTRL, (u8 *)(&acm_mask));
	else
		padapter->mlmepriv.acm_mask = acm_mask;

	inx[0] = 0; inx[1] = 1; inx[2] = 2; inx[3] = 3;

	if (pregpriv->wifi_spec == 1) {
		u32 j, change_inx = false;

		/* entry indx: 0->vo, 1->vi, 2->be, 3->bk. */
		for (i = 0; i < 4; i++) {
			for (j = i + 1; j < 4; j++) {
				/* compare CW and AIFS */
				if ((edca[j] & 0xFFFF) < (edca[i] & 0xFFFF)) {
					change_inx = true;
				} else if ((edca[j] & 0xFFFF) == (edca[i] & 0xFFFF)) {
					/* compare TXOP */
					if ((edca[j] >> 16) > (edca[i] >> 16))
						change_inx = true;
				}

				if (change_inx) {
					swap(edca[i], edca[j]);
					swap(inx[i], inx[j]);
					change_inx = false;
				}
			}
		}
	}

	for (i = 0; i < 4; i++) {
		pxmitpriv->wmm_para_seq[i] = inx[i];
		DBG_88E("wmm_para_seq(%d): %d\n", i, pxmitpriv->wmm_para_seq[i]);
	}
}