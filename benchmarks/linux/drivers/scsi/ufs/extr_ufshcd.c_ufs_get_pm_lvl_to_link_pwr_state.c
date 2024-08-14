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
typedef  enum uic_link_state { ____Placeholder_uic_link_state } uic_link_state ;
typedef  enum ufs_pm_level { ____Placeholder_ufs_pm_level } ufs_pm_level ;
struct TYPE_2__ {int link_state; } ;

/* Variables and functions */
 TYPE_1__* ufs_pm_lvl_states ; 

__attribute__((used)) static inline enum uic_link_state
ufs_get_pm_lvl_to_link_pwr_state(enum ufs_pm_level lvl)
{
	return ufs_pm_lvl_states[lvl].link_state;
}