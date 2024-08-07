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
struct bfa_fcs_lport_s {int /*<<< orphan*/  pid; int /*<<< orphan*/  fcs; } ;
struct bfa_fcs_lport_ns_s {int dummy; } ;

/* Variables and functions */
 struct bfa_fcs_lport_ns_s* BFA_FCS_GET_NS_FROM_PORT (struct bfa_fcs_lport_s*) ; 
 int /*<<< orphan*/  NSSM_EVENT_NS_QUERY ; 
 int /*<<< orphan*/  bfa_fcs_lport_ns_sm_online ; 
 scalar_t__ bfa_sm_cmp_state (struct bfa_fcs_lport_ns_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_sm_send_event (struct bfa_fcs_lport_ns_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_trc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
bfa_fcs_lport_ns_query(struct bfa_fcs_lport_s *port)
{
	struct bfa_fcs_lport_ns_s *ns = BFA_FCS_GET_NS_FROM_PORT(port);

	bfa_trc(port->fcs, port->pid);
	if (bfa_sm_cmp_state(ns, bfa_fcs_lport_ns_sm_online))
		bfa_sm_send_event(ns, NSSM_EVENT_NS_QUERY);
}