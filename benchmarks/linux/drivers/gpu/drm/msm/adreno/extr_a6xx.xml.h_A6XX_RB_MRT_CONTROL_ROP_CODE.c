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
typedef  int uint32_t ;
typedef  enum a3xx_rop_code { ____Placeholder_a3xx_rop_code } a3xx_rop_code ;

/* Variables and functions */
 int A6XX_RB_MRT_CONTROL_ROP_CODE__MASK ; 
 int A6XX_RB_MRT_CONTROL_ROP_CODE__SHIFT ; 

__attribute__((used)) static inline uint32_t A6XX_RB_MRT_CONTROL_ROP_CODE(enum a3xx_rop_code val)
{
	return ((val) << A6XX_RB_MRT_CONTROL_ROP_CODE__SHIFT) & A6XX_RB_MRT_CONTROL_ROP_CODE__MASK;
}