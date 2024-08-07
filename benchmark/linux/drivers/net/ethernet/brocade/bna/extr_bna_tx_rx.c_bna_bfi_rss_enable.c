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
struct bfi_enet_enable_req {TYPE_4__ mh; int /*<<< orphan*/  enable; } ;
struct TYPE_8__ {struct bfi_enet_enable_req req; } ;
struct bna_rxf {int /*<<< orphan*/  msgq_cmd; TYPE_2__* rx; int /*<<< orphan*/  rss_status; TYPE_3__ bfi_enet_cmd; } ;
struct TYPE_7__ {TYPE_1__* bna; int /*<<< orphan*/  rid; } ;
struct TYPE_6__ {int /*<<< orphan*/  msgq; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFI_ENET_H2I_RSS_ENABLE_REQ ; 
 int /*<<< orphan*/  BFI_MC_ENET ; 
 int /*<<< orphan*/  bfa_msgq_cmd_post (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bfa_msgq_cmd_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,TYPE_4__*) ; 
 int /*<<< orphan*/  bfi_msgq_mhdr_set (TYPE_4__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfi_msgq_num_cmd_entries (int) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bna_bfi_rss_enable(struct bna_rxf *rxf)
{
	struct bfi_enet_enable_req *req = &rxf->bfi_enet_cmd.req;

	bfi_msgq_mhdr_set(req->mh, BFI_MC_ENET,
		BFI_ENET_H2I_RSS_ENABLE_REQ, 0, rxf->rx->rid);
	req->mh.num_entries = htons(
		bfi_msgq_num_cmd_entries(sizeof(struct bfi_enet_enable_req)));
	req->enable = rxf->rss_status;
	bfa_msgq_cmd_set(&rxf->msgq_cmd, NULL, NULL,
		sizeof(struct bfi_enet_enable_req), &req->mh);
	bfa_msgq_cmd_post(&rxf->rx->bna->msgq, &rxf->msgq_cmd);
}