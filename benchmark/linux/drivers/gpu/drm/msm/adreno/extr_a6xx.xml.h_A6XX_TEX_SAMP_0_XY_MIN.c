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
typedef  enum a6xx_tex_filter { ____Placeholder_a6xx_tex_filter } a6xx_tex_filter ;

/* Variables and functions */
 int A6XX_TEX_SAMP_0_XY_MIN__MASK ; 
 int A6XX_TEX_SAMP_0_XY_MIN__SHIFT ; 

__attribute__((used)) static inline uint32_t A6XX_TEX_SAMP_0_XY_MIN(enum a6xx_tex_filter val)
{
	return ((val) << A6XX_TEX_SAMP_0_XY_MIN__SHIFT) & A6XX_TEX_SAMP_0_XY_MIN__MASK;
}