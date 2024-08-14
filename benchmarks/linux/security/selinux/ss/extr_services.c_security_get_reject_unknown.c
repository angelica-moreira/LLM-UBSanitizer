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
struct selinux_state {TYPE_2__* ss; } ;
struct TYPE_3__ {int reject_unknown; } ;
struct TYPE_4__ {TYPE_1__ policydb; } ;

/* Variables and functions */

int security_get_reject_unknown(struct selinux_state *state)
{
	return state->ss->policydb.reject_unknown;
}