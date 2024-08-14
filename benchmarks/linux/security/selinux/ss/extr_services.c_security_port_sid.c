#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct sidtab {int dummy; } ;
struct selinux_state {TYPE_3__* ss; } ;
struct policydb {struct ocontext** ocontexts; } ;
struct TYPE_4__ {scalar_t__ protocol; scalar_t__ low_port; scalar_t__ high_port; } ;
struct TYPE_5__ {TYPE_1__ port; } ;
struct ocontext {scalar_t__* sid; int /*<<< orphan*/ * context; struct ocontext* next; TYPE_2__ u; } ;
struct TYPE_6__ {int /*<<< orphan*/  policy_rwlock; struct sidtab* sidtab; struct policydb policydb; } ;

/* Variables and functions */
 size_t OCON_PORT ; 
 scalar_t__ SECINITSID_PORT ; 
 int /*<<< orphan*/  read_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  read_unlock (int /*<<< orphan*/ *) ; 
 int sidtab_context_to_sid (struct sidtab*,int /*<<< orphan*/ *,scalar_t__*) ; 

int security_port_sid(struct selinux_state *state,
		      u8 protocol, u16 port, u32 *out_sid)
{
	struct policydb *policydb;
	struct sidtab *sidtab;
	struct ocontext *c;
	int rc = 0;

	read_lock(&state->ss->policy_rwlock);

	policydb = &state->ss->policydb;
	sidtab = state->ss->sidtab;

	c = policydb->ocontexts[OCON_PORT];
	while (c) {
		if (c->u.port.protocol == protocol &&
		    c->u.port.low_port <= port &&
		    c->u.port.high_port >= port)
			break;
		c = c->next;
	}

	if (c) {
		if (!c->sid[0]) {
			rc = sidtab_context_to_sid(sidtab,
						   &c->context[0],
						   &c->sid[0]);
			if (rc)
				goto out;
		}
		*out_sid = c->sid[0];
	} else {
		*out_sid = SECINITSID_PORT;
	}

out:
	read_unlock(&state->ss->policy_rwlock);
	return rc;
}