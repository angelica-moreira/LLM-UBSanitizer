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
struct hal_com_data {int SdioTxOQTMaxFreeSpace; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 struct hal_com_data* GET_HAL_DATA (struct adapter*) ; 

u8 rtw_hal_sdio_max_txoqt_free_space(struct adapter *padapter)
{
	struct hal_com_data	*pHalData = GET_HAL_DATA(padapter);

	if (pHalData->SdioTxOQTMaxFreeSpace < 8)
		pHalData->SdioTxOQTMaxFreeSpace = 8;

	return pHalData->SdioTxOQTMaxFreeSpace;
}