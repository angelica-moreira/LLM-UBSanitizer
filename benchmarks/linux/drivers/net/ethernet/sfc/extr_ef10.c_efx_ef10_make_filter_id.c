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
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;

/* Variables and functions */
 unsigned int HUNT_FILTER_TBL_ROWS ; 

__attribute__((used)) static u32 efx_ef10_make_filter_id(unsigned int pri, u16 idx)
{
	return pri * HUNT_FILTER_TBL_ROWS * 2 + idx;
}