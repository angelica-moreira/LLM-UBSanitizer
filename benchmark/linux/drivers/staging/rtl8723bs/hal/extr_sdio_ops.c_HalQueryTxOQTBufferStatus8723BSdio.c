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
struct hal_com_data {int /*<<< orphan*/  SdioTxOQTFreeSpace; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 struct hal_com_data* GET_HAL_DATA (struct adapter*) ; 
 int /*<<< orphan*/  SDIO_REG_OQT_FREE_PG ; 
 int /*<<< orphan*/  SdioLocalCmd52Read1Byte (struct adapter*,int /*<<< orphan*/ ) ; 

void HalQueryTxOQTBufferStatus8723BSdio(struct adapter *adapter)
{
	struct hal_com_data *haldata = GET_HAL_DATA(adapter);

	haldata->SdioTxOQTFreeSpace = SdioLocalCmd52Read1Byte(adapter, SDIO_REG_OQT_FREE_PG);
}