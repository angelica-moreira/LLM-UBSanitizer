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

/* Variables and functions */
 int A4XX_RB_BLEND_BLUE_F32__MASK ; 
 int A4XX_RB_BLEND_BLUE_F32__SHIFT ; 
 int fui (float) ; 

__attribute__((used)) static inline uint32_t A4XX_RB_BLEND_BLUE_F32(float val)
{
	return ((fui(val)) << A4XX_RB_BLEND_BLUE_F32__SHIFT) & A4XX_RB_BLEND_BLUE_F32__MASK;
}