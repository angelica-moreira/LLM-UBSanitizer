#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_2__ {int debug_level; } ;

/* Variables and functions */
 TYPE_1__ iwlwifi_mod_params ; 

__attribute__((used)) static inline bool iwl_have_debug_level(u32 level)
{
#ifdef CONFIG_IWLWIFI_DEBUG
	return iwlwifi_mod_params.debug_level & level;
#else
	return false;
#endif
}