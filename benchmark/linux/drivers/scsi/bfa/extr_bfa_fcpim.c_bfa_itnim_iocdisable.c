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
struct bfa_itnim_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_ITNIM_SM_HWFAIL ; 
 int /*<<< orphan*/  bfa_sm_send_event (struct bfa_itnim_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_stats (struct bfa_itnim_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioc_disabled ; 

void
bfa_itnim_iocdisable(struct bfa_itnim_s *itnim)
{
	bfa_stats(itnim, ioc_disabled);
	bfa_sm_send_event(itnim, BFA_ITNIM_SM_HWFAIL);
}