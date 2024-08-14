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
typedef  enum a2xx_rb_dither_type { ____Placeholder_a2xx_rb_dither_type } a2xx_rb_dither_type ;

/* Variables and functions */
 int A2XX_RB_COLORCONTROL_DITHER_TYPE__MASK ; 
 int A2XX_RB_COLORCONTROL_DITHER_TYPE__SHIFT ; 

__attribute__((used)) static inline uint32_t A2XX_RB_COLORCONTROL_DITHER_TYPE(enum a2xx_rb_dither_type val)
{
	return ((val) << A2XX_RB_COLORCONTROL_DITHER_TYPE__SHIFT) & A2XX_RB_COLORCONTROL_DITHER_TYPE__MASK;
}