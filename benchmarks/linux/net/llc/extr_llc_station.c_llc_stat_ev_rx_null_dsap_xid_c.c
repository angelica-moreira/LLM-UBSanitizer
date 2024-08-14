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
struct sk_buff {int dummy; } ;
struct llc_pdu_un {int /*<<< orphan*/  dsap; } ;

/* Variables and functions */
 scalar_t__ LLC_1_PDU_CMD_XID ; 
 scalar_t__ LLC_PDU_IS_CMD (struct llc_pdu_un*) ; 
 scalar_t__ LLC_PDU_TYPE_IS_U (struct llc_pdu_un*) ; 
 scalar_t__ LLC_U_PDU_CMD (struct llc_pdu_un*) ; 
 struct llc_pdu_un* llc_pdu_un_hdr (struct sk_buff*) ; 

__attribute__((used)) static int llc_stat_ev_rx_null_dsap_xid_c(struct sk_buff *skb)
{
	struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);

	return LLC_PDU_IS_CMD(pdu) &&			/* command PDU */
	       LLC_PDU_TYPE_IS_U(pdu) &&		/* U type PDU */
	       LLC_U_PDU_CMD(pdu) == LLC_1_PDU_CMD_XID &&
	       !pdu->dsap ? 0 : 1;			/* NULL DSAP value */
}