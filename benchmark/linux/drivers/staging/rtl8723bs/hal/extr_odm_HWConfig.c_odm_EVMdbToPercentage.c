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
typedef  int s8 ;

/* Variables and functions */

__attribute__((used)) static u8 odm_EVMdbToPercentage(s8 Value)
{
	/*  */
	/*  -33dB~0dB to 0%~99% */
	/*  */
	s8 ret_val;

	ret_val = Value;
	ret_val /= 2;

	/* DbgPrint("Value =%d\n", Value); */
	/* ODM_RT_DISP(FRX, RX_PHY_SQ, ("EVMdbToPercentage92C Value =%d / %x\n", ret_val, ret_val)); */

	if (ret_val >= 0)
		ret_val = 0;
	if (ret_val <= -33)
		ret_val = -33;

	ret_val = 0 - ret_val;
	ret_val *= 3;

	if (ret_val == 99)
		ret_val = 100;

	return ret_val;
}