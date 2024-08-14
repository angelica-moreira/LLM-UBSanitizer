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
struct selinux_state {int* policycap; } ;

/* Variables and functions */
 size_t POLICYDB_CAPABILITY_ALWAYSNETWORK ; 
 struct selinux_state selinux_state ; 

__attribute__((used)) static inline bool selinux_policycap_alwaysnetwork(void)
{
	struct selinux_state *state = &selinux_state;

	return state->policycap[POLICYDB_CAPABILITY_ALWAYSNETWORK];
}