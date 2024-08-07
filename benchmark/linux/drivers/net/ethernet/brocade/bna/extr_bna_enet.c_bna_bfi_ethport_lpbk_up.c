#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  num_entries; } ;
struct bfi_enet_diag_lb_req {TYPE_4__ mh; int /*<<< orphan*/  enable; int /*<<< orphan*/  mode; } ;
struct TYPE_6__ {struct bfi_enet_diag_lb_req lpbk_req; } ;
struct bna_ethport {int /*<<< orphan*/  msgq_cmd; TYPE_3__* bna; TYPE_1__ bfi_enet_cmd; } ;
struct TYPE_7__ {scalar_t__ type; } ;
struct TYPE_8__ {int /*<<< orphan*/  msgq; TYPE_2__ enet; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFI_ENET_DIAG_LB_OPMODE_CBL ; 
 int /*<<< orphan*/  BFI_ENET_DIAG_LB_OPMODE_EXT ; 
 int /*<<< orphan*/  BFI_ENET_H2I_DIAG_LOOPBACK_REQ ; 
 int /*<<< orphan*/  BFI_MC_ENET ; 
 scalar_t__ BNA_ENET_T_LOOPBACK_INTERNAL ; 
 int /*<<< orphan*/  BNA_STATUS_T_ENABLED ; 
 int /*<<< orphan*/  bfa_msgq_cmd_post (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bfa_msgq_cmd_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,TYPE_4__*) ; 
 int /*<<< orphan*/  bfi_msgq_mhdr_set (TYPE_4__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfi_msgq_num_cmd_entries (int) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bna_bfi_ethport_lpbk_up(struct bna_ethport *ethport)
{
	struct bfi_enet_diag_lb_req *lpbk_up_req =
		&ethport->bfi_enet_cmd.lpbk_req;

	bfi_msgq_mhdr_set(lpbk_up_req->mh, BFI_MC_ENET,
		BFI_ENET_H2I_DIAG_LOOPBACK_REQ, 0, 0);
	lpbk_up_req->mh.num_entries = htons(
		bfi_msgq_num_cmd_entries(sizeof(struct bfi_enet_diag_lb_req)));
	lpbk_up_req->mode = (ethport->bna->enet.type ==
				BNA_ENET_T_LOOPBACK_INTERNAL) ?
				BFI_ENET_DIAG_LB_OPMODE_EXT :
				BFI_ENET_DIAG_LB_OPMODE_CBL;
	lpbk_up_req->enable = BNA_STATUS_T_ENABLED;

	bfa_msgq_cmd_set(&ethport->msgq_cmd, NULL, NULL,
		sizeof(struct bfi_enet_diag_lb_req), &lpbk_up_req->mh);
	bfa_msgq_cmd_post(&ethport->bna->msgq, &ethport->msgq_cmd);
}