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
typedef  scalar_t__ u64 ;

/* Variables and functions */
 scalar_t__ PM_ISLAND4_BASE_SIGNAL_GROUP_NUMBER ; 

__attribute__((used)) static u64 pm_translate_signal_group_number_on_island4(u64 subgroup)
{
	return PM_ISLAND4_BASE_SIGNAL_GROUP_NUMBER + subgroup;
}