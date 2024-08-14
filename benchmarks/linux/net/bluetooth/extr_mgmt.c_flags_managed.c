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
typedef  int u32 ;

/* Variables and functions */
 int MGMT_ADV_FLAG_DISCOV ; 
 int MGMT_ADV_FLAG_LIMITED_DISCOV ; 
 int MGMT_ADV_FLAG_MANAGED_FLAGS ; 

__attribute__((used)) static bool flags_managed(u32 adv_flags)
{
	return adv_flags & (MGMT_ADV_FLAG_DISCOV |
			    MGMT_ADV_FLAG_LIMITED_DISCOV |
			    MGMT_ADV_FLAG_MANAGED_FLAGS);
}