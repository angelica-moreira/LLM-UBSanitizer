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
typedef  enum adreno_rb_depth_format { ____Placeholder_adreno_rb_depth_format } adreno_rb_depth_format ;

/* Variables and functions */
 int A2XX_RB_DEPTH_INFO_DEPTH_FORMAT__MASK ; 
 int A2XX_RB_DEPTH_INFO_DEPTH_FORMAT__SHIFT ; 

__attribute__((used)) static inline uint32_t A2XX_RB_DEPTH_INFO_DEPTH_FORMAT(enum adreno_rb_depth_format val)
{
	return ((val) << A2XX_RB_DEPTH_INFO_DEPTH_FORMAT__SHIFT) & A2XX_RB_DEPTH_INFO_DEPTH_FORMAT__MASK;
}