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
struct bfa_fcs_vport_s {int /*<<< orphan*/  timer; int /*<<< orphan*/  lport; int /*<<< orphan*/  lps; } ;
typedef  enum bfa_fcs_vport_event { ____Placeholder_bfa_fcs_vport_event } bfa_fcs_vport_event ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_FCS_RETRY_TIMEOUT ; 
#define  BFA_FCS_VPORT_SM_DELETE 134 
#define  BFA_FCS_VPORT_SM_FABRIC_MAX 133 
#define  BFA_FCS_VPORT_SM_OFFLINE 132 
#define  BFA_FCS_VPORT_SM_RSP_DUP_WWN 131 
#define  BFA_FCS_VPORT_SM_RSP_ERROR 130 
#define  BFA_FCS_VPORT_SM_RSP_FAILED 129 
#define  BFA_FCS_VPORT_SM_RSP_OK 128 
 int /*<<< orphan*/  BFA_LPS_SM_OFFLINE ; 
 int /*<<< orphan*/  __vport_bfa (struct bfa_fcs_vport_s*) ; 
 int /*<<< orphan*/  __vport_fcs (struct bfa_fcs_vport_s*) ; 
 int __vport_pwwn (struct bfa_fcs_vport_s*) ; 
 int /*<<< orphan*/  bfa_fcs_lport_online (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bfa_fcs_vport_sm_error ; 
 int /*<<< orphan*/  bfa_fcs_vport_sm_fdisc_retry ; 
 int /*<<< orphan*/  bfa_fcs_vport_sm_fdisc_rsp_wait ; 
 int /*<<< orphan*/  bfa_fcs_vport_sm_offline ; 
 int /*<<< orphan*/  bfa_fcs_vport_sm_online ; 
 int /*<<< orphan*/  bfa_fcs_vport_timeout ; 
 int /*<<< orphan*/  bfa_sm_fault (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bfa_sm_send_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_sm_set_state (struct bfa_fcs_vport_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_timer_start (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct bfa_fcs_vport_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_trc (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
bfa_fcs_vport_sm_fdisc(struct bfa_fcs_vport_s *vport,
			enum bfa_fcs_vport_event event)
{
	bfa_trc(__vport_fcs(vport), __vport_pwwn(vport));
	bfa_trc(__vport_fcs(vport), event);

	switch (event) {
	case BFA_FCS_VPORT_SM_DELETE:
		bfa_sm_set_state(vport, bfa_fcs_vport_sm_fdisc_rsp_wait);
		break;

	case BFA_FCS_VPORT_SM_OFFLINE:
		bfa_sm_set_state(vport, bfa_fcs_vport_sm_offline);
		bfa_sm_send_event(vport->lps, BFA_LPS_SM_OFFLINE);
		break;

	case BFA_FCS_VPORT_SM_RSP_OK:
		bfa_sm_set_state(vport, bfa_fcs_vport_sm_online);
		bfa_fcs_lport_online(&vport->lport);
		break;

	case BFA_FCS_VPORT_SM_RSP_ERROR:
		bfa_sm_set_state(vport, bfa_fcs_vport_sm_fdisc_retry);
		bfa_timer_start(__vport_bfa(vport), &vport->timer,
				    bfa_fcs_vport_timeout, vport,
				    BFA_FCS_RETRY_TIMEOUT);
		break;

	case BFA_FCS_VPORT_SM_RSP_FAILED:
	case BFA_FCS_VPORT_SM_FABRIC_MAX:
		bfa_sm_set_state(vport, bfa_fcs_vport_sm_offline);
		break;

	case BFA_FCS_VPORT_SM_RSP_DUP_WWN:
		bfa_sm_set_state(vport, bfa_fcs_vport_sm_error);
		break;

	default:
		bfa_sm_fault(__vport_fcs(vport), event);
	}
}