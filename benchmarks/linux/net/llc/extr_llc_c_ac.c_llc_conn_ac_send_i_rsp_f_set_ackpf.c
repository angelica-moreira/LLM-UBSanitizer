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
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  mac; int /*<<< orphan*/  lsap; } ;
struct llc_sock {TYPE_2__ daddr; TYPE_1__* dev; int /*<<< orphan*/  vR; int /*<<< orphan*/  vS; int /*<<< orphan*/  ack_pf; struct llc_sap* sap; } ;
struct TYPE_6__ {int /*<<< orphan*/  lsap; } ;
struct llc_sap {TYPE_3__ laddr; } ;
struct TYPE_4__ {int /*<<< orphan*/  dev_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  LLC_PDU_RSP ; 
 int /*<<< orphan*/  LLC_PDU_TYPE_I ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  llc_conn_ac_inc_vs_by_1 (struct sock*,struct sk_buff*) ; 
 int /*<<< orphan*/  llc_conn_send_pdu (struct sock*,struct sk_buff*) ; 
 int llc_mac_hdr_init (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  llc_pdu_header_init (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  llc_pdu_init_as_i_cmd (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct llc_sock* llc_sk (struct sock*) ; 
 int /*<<< orphan*/  skb_get (struct sk_buff*) ; 

__attribute__((used)) static int llc_conn_ac_send_i_rsp_f_set_ackpf(struct sock *sk,
					      struct sk_buff *skb)
{
	int rc;
	struct llc_sock *llc = llc_sk(sk);
	struct llc_sap *sap = llc->sap;

	llc_pdu_header_init(skb, LLC_PDU_TYPE_I, sap->laddr.lsap,
			    llc->daddr.lsap, LLC_PDU_RSP);
	llc_pdu_init_as_i_cmd(skb, llc->ack_pf, llc->vS, llc->vR);
	rc = llc_mac_hdr_init(skb, llc->dev->dev_addr, llc->daddr.mac);
	if (likely(!rc)) {
		skb_get(skb);
		llc_conn_send_pdu(sk, skb);
		llc_conn_ac_inc_vs_by_1(sk, skb);
	}
	return rc;
}