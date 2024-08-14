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
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  C2HPacketHandler_8723B (struct adapter*,int*,int) ; 
#define  HW_VAR_C2H_HANDLE 128 

__attribute__((used)) static void SetHwRegWithBuf8723B(struct adapter *padapter, u8 variable, u8 *pbuf, int len)
{
	switch (variable) {
	case HW_VAR_C2H_HANDLE:
		/* DBG_8192C("%s len =%d\n", __func__, len); */
		C2HPacketHandler_8723B(padapter, pbuf, len);
		break;
	default:
		break;
	}
}