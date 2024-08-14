#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct bna_rx {int /*<<< orphan*/  rxf; TYPE_1__* bna; int /*<<< orphan*/  (* rx_cleanup_cbfn ) (int /*<<< orphan*/ ,struct bna_rx*) ;} ;
typedef  enum bna_rx_event { ____Placeholder_bna_rx_event } bna_rx_event ;
struct TYPE_2__ {int /*<<< orphan*/  bnad; } ;

/* Variables and functions */
#define  RX_E_FAIL 130 
#define  RX_E_RXF_STARTED 129 
#define  RX_E_RXF_STOPPED 128 
 int /*<<< orphan*/  bfa_fsm_set_state (struct bna_rx*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_sm_fault (int) ; 
 int /*<<< orphan*/  bna_rx_enet_stop (struct bna_rx*) ; 
 int /*<<< orphan*/  bna_rx_sm_cleanup_wait ; 
 int /*<<< orphan*/  bna_rx_sm_stop_wait ; 
 int /*<<< orphan*/  bna_rxf_fail (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bna_rxf_stop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  call_rx_stall_cbfn (struct bna_rx*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,struct bna_rx*) ; 

__attribute__((used)) static void
bna_rx_sm_rxf_stop_wait(struct bna_rx *rx, enum bna_rx_event event)
{
	switch (event) {
	case RX_E_FAIL:
		bfa_fsm_set_state(rx, bna_rx_sm_cleanup_wait);
		bna_rxf_fail(&rx->rxf);
		call_rx_stall_cbfn(rx);
		rx->rx_cleanup_cbfn(rx->bna->bnad, rx);
		break;

	case RX_E_RXF_STARTED:
		bna_rxf_stop(&rx->rxf);
		break;

	case RX_E_RXF_STOPPED:
		bfa_fsm_set_state(rx, bna_rx_sm_stop_wait);
		call_rx_stall_cbfn(rx);
		bna_rx_enet_stop(rx);
		break;

	default:
		bfa_sm_fault(event);
		break;
	}

}