#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_7__ {int curAmpduTimeType; int preAmpduTimeType; int backupAmpduMaxTime; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* fBtcWrite1Byte ) (TYPE_1__*,int,int) ;} ;
typedef  TYPE_1__* PBTC_COEXIST ;

/* Variables and functions */
 TYPE_4__* pCoexDm ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int,int) ; 

__attribute__((used)) static void halbtc8723b1ant_AmpduMaxTime(
	PBTC_COEXIST pBtCoexist, bool bForceExec, u8 type
)
{
	pCoexDm->curAmpduTimeType = type;

	if (
		bForceExec || (pCoexDm->preAmpduTimeType != pCoexDm->curAmpduTimeType)
	) {
		switch (pCoexDm->curAmpduTimeType) {
		case 0:	/*  normal mode */
			pBtCoexist->fBtcWrite1Byte(
				pBtCoexist, 0x456, pCoexDm->backupAmpduMaxTime
			);
			break;
		case 1:	/*  AMPDU timw = 0x38 * 32us */
			pBtCoexist->fBtcWrite1Byte(pBtCoexist, 0x456, 0x38);
			break;
		default:
			break;
		}
	}

	pCoexDm->preAmpduTimeType = pCoexDm->curAmpduTimeType;
}