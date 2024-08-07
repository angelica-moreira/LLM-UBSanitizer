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
struct bna_enet {int flags; } ;
typedef  enum bna_enet_event { ____Placeholder_bna_enet_event } bna_enet_event ;

/* Variables and functions */
 int BNA_ENET_F_MTU_CHANGED ; 
 int BNA_ENET_F_PAUSE_CHANGED ; 
#define  ENET_E_CHLD_STOPPED 133 
#define  ENET_E_FAIL 132 
#define  ENET_E_FWRESP_PAUSE 131 
#define  ENET_E_MTU_CFG 130 
#define  ENET_E_PAUSE_CFG 129 
#define  ENET_E_STOP 128 
 int /*<<< orphan*/  bfa_fsm_set_state (struct bna_enet*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_sm_fault (int) ; 
 int /*<<< orphan*/  bna_bfi_pause_set (struct bna_enet*) ; 
 int /*<<< orphan*/  bna_enet_chld_fail (struct bna_enet*) ; 
 int /*<<< orphan*/  bna_enet_rx_start (struct bna_enet*) ; 
 int /*<<< orphan*/  bna_enet_rx_stop (struct bna_enet*) ; 
 int /*<<< orphan*/  bna_enet_sm_cfg_stop_wait ; 
 int /*<<< orphan*/  bna_enet_sm_started ; 
 int /*<<< orphan*/  bna_enet_sm_stopped ; 

__attribute__((used)) static void
bna_enet_sm_cfg_wait(struct bna_enet *enet,
			enum bna_enet_event event)
{
	switch (event) {
	case ENET_E_STOP:
		enet->flags &= ~BNA_ENET_F_PAUSE_CHANGED;
		enet->flags &= ~BNA_ENET_F_MTU_CHANGED;
		bfa_fsm_set_state(enet, bna_enet_sm_cfg_stop_wait);
		break;

	case ENET_E_FAIL:
		enet->flags &= ~BNA_ENET_F_PAUSE_CHANGED;
		enet->flags &= ~BNA_ENET_F_MTU_CHANGED;
		bfa_fsm_set_state(enet, bna_enet_sm_stopped);
		bna_enet_chld_fail(enet);
		break;

	case ENET_E_PAUSE_CFG:
		enet->flags |= BNA_ENET_F_PAUSE_CHANGED;
		break;

	case ENET_E_MTU_CFG:
		enet->flags |= BNA_ENET_F_MTU_CHANGED;
		break;

	case ENET_E_CHLD_STOPPED:
		bna_enet_rx_start(enet);
		/* Fall through */
	case ENET_E_FWRESP_PAUSE:
		if (enet->flags & BNA_ENET_F_PAUSE_CHANGED) {
			enet->flags &= ~BNA_ENET_F_PAUSE_CHANGED;
			bna_bfi_pause_set(enet);
		} else if (enet->flags & BNA_ENET_F_MTU_CHANGED) {
			enet->flags &= ~BNA_ENET_F_MTU_CHANGED;
			bna_enet_rx_stop(enet);
		} else {
			bfa_fsm_set_state(enet, bna_enet_sm_started);
		}
		break;

	default:
		bfa_sm_fault(event);
	}
}