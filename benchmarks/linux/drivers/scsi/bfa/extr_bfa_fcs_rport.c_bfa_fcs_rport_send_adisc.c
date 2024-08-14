#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct fchs_s {int dummy; } ;
struct bfa_fcxp_s {int dummy; } ;
struct TYPE_7__ {int /*<<< orphan*/  adisc_sent; } ;
struct bfa_fcs_rport_s {TYPE_3__ stats; int /*<<< orphan*/  pid; struct bfa_fcxp_s* fcxp; int /*<<< orphan*/  fcxp_wqe; int /*<<< orphan*/  pwwn; int /*<<< orphan*/  fcs; struct bfa_fcs_lport_s* port; } ;
struct TYPE_5__ {int /*<<< orphan*/  nwwn; int /*<<< orphan*/  pwwn; } ;
struct bfa_fcs_lport_s {int /*<<< orphan*/  lp_tag; TYPE_2__* fabric; TYPE_1__ port_cfg; TYPE_4__* fcs; } ;
struct TYPE_8__ {int /*<<< orphan*/  bfa; } ;
struct TYPE_6__ {int /*<<< orphan*/  vf_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_FALSE ; 
 int /*<<< orphan*/  BFA_TRUE ; 
 int /*<<< orphan*/  FC_CLASS_3 ; 
 int /*<<< orphan*/  FC_ELS_TOV ; 
 int /*<<< orphan*/  FC_MAX_PDUSZ ; 
 int /*<<< orphan*/  RPSM_EVENT_FCXP_SENT ; 
 struct bfa_fcxp_s* bfa_fcs_fcxp_alloc (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_fcs_fcxp_alloc_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ *,void (*) (void*,struct bfa_fcxp_s*),struct bfa_fcs_rport_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_fcs_lport_get_fcid (struct bfa_fcs_lport_s*) ; 
 int /*<<< orphan*/  bfa_fcs_rport_adisc_response ; 
 int /*<<< orphan*/  bfa_fcxp_get_reqbuf (struct bfa_fcxp_s*) ; 
 int /*<<< orphan*/  bfa_fcxp_send (struct bfa_fcxp_s*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,struct fchs_s*,int /*<<< orphan*/ ,struct bfa_fcs_rport_s*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_sm_send_event (struct bfa_fcs_rport_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_trc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int fc_adisc_build (struct fchs_s*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bfa_fcs_rport_send_adisc(void *rport_cbarg, struct bfa_fcxp_s *fcxp_alloced)
{
	struct bfa_fcs_rport_s *rport = rport_cbarg;
	struct bfa_fcs_lport_s *port = rport->port;
	struct fchs_s		fchs;
	int		len;
	struct bfa_fcxp_s *fcxp;

	bfa_trc(rport->fcs, rport->pwwn);

	fcxp = fcxp_alloced ? fcxp_alloced :
	       bfa_fcs_fcxp_alloc(port->fcs, BFA_TRUE);
	if (!fcxp) {
		bfa_fcs_fcxp_alloc_wait(port->fcs->bfa, &rport->fcxp_wqe,
				bfa_fcs_rport_send_adisc, rport, BFA_TRUE);
		return;
	}
	rport->fcxp = fcxp;

	len = fc_adisc_build(&fchs, bfa_fcxp_get_reqbuf(fcxp), rport->pid,
				bfa_fcs_lport_get_fcid(port), 0,
				port->port_cfg.pwwn, port->port_cfg.nwwn);

	bfa_fcxp_send(fcxp, NULL, port->fabric->vf_id, port->lp_tag, BFA_FALSE,
			FC_CLASS_3, len, &fchs, bfa_fcs_rport_adisc_response,
			rport, FC_MAX_PDUSZ, FC_ELS_TOV);

	rport->stats.adisc_sent++;
	bfa_sm_send_event(rport, RPSM_EVENT_FCXP_SENT);
}