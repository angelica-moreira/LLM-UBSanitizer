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
typedef  enum adreno_rb_dither_mode { ____Placeholder_adreno_rb_dither_mode } adreno_rb_dither_mode ;

/* Variables and functions */
 int A2XX_RB_COPY_DEST_INFO_DITHER_MODE__MASK ; 
 int A2XX_RB_COPY_DEST_INFO_DITHER_MODE__SHIFT ; 

__attribute__((used)) static inline uint32_t A2XX_RB_COPY_DEST_INFO_DITHER_MODE(enum adreno_rb_dither_mode val)
{
	return ((val) << A2XX_RB_COPY_DEST_INFO_DITHER_MODE__SHIFT) & A2XX_RB_COPY_DEST_INFO_DITHER_MODE__MASK;
}