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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int bRFRegOffsetMask ; 
 int phy_CalculateBitShift (int) ; 
 int phy_RFSerialRead_8723B (struct adapter*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  phy_RFSerialWrite_8723B (struct adapter*,int /*<<< orphan*/ ,int,int) ; 

void PHY_SetRFReg_8723B(
	struct adapter *Adapter,
	u8 eRFPath,
	u32 RegAddr,
	u32 BitMask,
	u32 Data
)
{
	u32 Original_Value, BitShift;

#if (DISABLE_BB_RF == 1)
	return;
#endif

	/*  RF data is 12 bits only */
	if (BitMask != bRFRegOffsetMask) {
		Original_Value = phy_RFSerialRead_8723B(Adapter, eRFPath, RegAddr);
		BitShift =  phy_CalculateBitShift(BitMask);
		Data = ((Original_Value & (~BitMask)) | (Data<<BitShift));
	}

	phy_RFSerialWrite_8723B(Adapter, eRFPath, RegAddr, Data);
}