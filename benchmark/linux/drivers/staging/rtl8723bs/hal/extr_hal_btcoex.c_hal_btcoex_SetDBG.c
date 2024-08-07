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
typedef  size_t u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 size_t BTC_MSG_MAX ; 
 size_t* GLBtcDbgType ; 

void hal_btcoex_SetDBG(struct adapter *padapter, u32 *pDbgModule)
{
	u32 i;


	if (!pDbgModule)
		return;

	for (i = 0; i < BTC_MSG_MAX; i++)
		GLBtcDbgType[i] = pDbgModule[i];
}