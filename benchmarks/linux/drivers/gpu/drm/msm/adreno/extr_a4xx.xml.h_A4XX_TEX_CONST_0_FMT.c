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
typedef  enum a4xx_tex_fmt { ____Placeholder_a4xx_tex_fmt } a4xx_tex_fmt ;

/* Variables and functions */
 int A4XX_TEX_CONST_0_FMT__MASK ; 
 int A4XX_TEX_CONST_0_FMT__SHIFT ; 

__attribute__((used)) static inline uint32_t A4XX_TEX_CONST_0_FMT(enum a4xx_tex_fmt val)
{
	return ((val) << A4XX_TEX_CONST_0_FMT__SHIFT) & A4XX_TEX_CONST_0_FMT__MASK;
}