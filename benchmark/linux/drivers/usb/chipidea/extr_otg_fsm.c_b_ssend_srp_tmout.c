#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int b_ssend_srp; TYPE_1__* otg; } ;
struct ci_hdrc {TYPE_2__ fsm; } ;
struct TYPE_3__ {scalar_t__ state; } ;

/* Variables and functions */
 scalar_t__ OTG_STATE_B_IDLE ; 

__attribute__((used)) static int b_ssend_srp_tmout(struct ci_hdrc *ci)
{
	ci->fsm.b_ssend_srp = 1;
	/* only vbus fall below B_sess_vld in b_idle state */
	if (ci->fsm.otg->state == OTG_STATE_B_IDLE)
		return 0;
	else
		return 1;
}