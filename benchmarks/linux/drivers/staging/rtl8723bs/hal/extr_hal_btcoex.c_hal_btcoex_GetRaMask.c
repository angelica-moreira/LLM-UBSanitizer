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
typedef  int /*<<< orphan*/  u32 ;
struct adapter {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  raMask; scalar_t__ bBtDisabled; } ;
struct TYPE_4__ {int btdmAntNum; } ;
struct TYPE_6__ {TYPE_2__ btInfo; TYPE_1__ boardInfo; } ;

/* Variables and functions */
 TYPE_3__ GLBtCoexist ; 
 int /*<<< orphan*/  hal_btcoex_IsBtExist (struct adapter*) ; 

u32 hal_btcoex_GetRaMask(struct adapter *padapter)
{
	if (!hal_btcoex_IsBtExist(padapter))
		return 0;

	if (GLBtCoexist.btInfo.bBtDisabled)
		return 0;

	if (GLBtCoexist.boardInfo.btdmAntNum != 1)
		return 0;

	return GLBtCoexist.btInfo.raMask;
}