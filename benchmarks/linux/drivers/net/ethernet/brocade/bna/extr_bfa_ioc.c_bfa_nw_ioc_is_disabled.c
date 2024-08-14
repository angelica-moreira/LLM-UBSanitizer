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
struct bfa_ioc {int dummy; } ;

/* Variables and functions */
 scalar_t__ bfa_fsm_cmp_state (struct bfa_ioc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_ioc_sm_disabled ; 
 int /*<<< orphan*/  bfa_ioc_sm_disabling ; 

bool
bfa_nw_ioc_is_disabled(struct bfa_ioc *ioc)
{
	return bfa_fsm_cmp_state(ioc, bfa_ioc_sm_disabling) ||
		bfa_fsm_cmp_state(ioc, bfa_ioc_sm_disabled);
}