#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sock {scalar_t__ sk_state; } ;
struct sk_buff {int dummy; } ;
struct request_sock {struct sock* rsk_listener; } ;
struct iphdr {int /*<<< orphan*/  daddr; int /*<<< orphan*/  saddr; } ;
struct dccp_hdr {scalar_t__ dccph_type; int dccph_cscov; int dccph_doff; int /*<<< orphan*/  dccph_dport; int /*<<< orphan*/  dccph_sport; } ;
struct TYPE_4__ {scalar_t__ dccpd_type; int /*<<< orphan*/  dccpd_reset_code; scalar_t__ dccpd_ack_seq; scalar_t__ dccpd_seq; } ;
struct TYPE_3__ {int dccps_pcrlen; } ;

/* Variables and functions */
 scalar_t__ DCCP_LISTEN ; 
 scalar_t__ DCCP_NEW_SYN_RECV ; 
 scalar_t__ DCCP_PKT_RESET ; 
 scalar_t__ DCCP_PKT_WITHOUT_ACK_SEQ ; 
 int /*<<< orphan*/  DCCP_RESET_CODE_NO_CONNECTION ; 
 TYPE_2__* DCCP_SKB_CB (struct sk_buff*) ; 
 scalar_t__ DCCP_TIME_WAIT ; 
 int /*<<< orphan*/  DCCP_WARN (char*) ; 
 int /*<<< orphan*/  XFRM_POLICY_IN ; 
 int /*<<< orphan*/  __dccp_hdr_len (struct dccp_hdr const*) ; 
 struct sock* __inet_lookup_skb (int /*<<< orphan*/ *,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int __sk_receive_skb (struct sock*,struct sk_buff*,int,int,int) ; 
 struct sock* dccp_check_req (struct sock*,struct sk_buff*,struct request_sock*) ; 
 scalar_t__ dccp_child_process (struct sock*,struct sock*,struct sk_buff*) ; 
 int /*<<< orphan*/  dccp_hashinfo ; 
 struct dccp_hdr* dccp_hdr (struct sk_buff*) ; 
 scalar_t__ dccp_hdr_ack_seq (struct sk_buff*) ; 
 scalar_t__ dccp_hdr_seq (struct dccp_hdr const*) ; 
 scalar_t__ dccp_invalid_packet (struct sk_buff*) ; 
 int /*<<< orphan*/  dccp_packet_name (scalar_t__) ; 
 scalar_t__ dccp_packet_without_ack (struct sk_buff*) ; 
 int /*<<< orphan*/  dccp_pr_debug (char*,...) ; 
 int /*<<< orphan*/  dccp_pr_debug_cat (char*,...) ; 
 TYPE_1__* dccp_sk (struct sock*) ; 
 scalar_t__ dccp_v4_csum_finish (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dccp_v4_ctl_send_reset (struct sock*,struct sk_buff*) ; 
 int /*<<< orphan*/  inet_csk_reqsk_queue_drop_and_put (struct sock*,struct request_sock*) ; 
 struct request_sock* inet_reqsk (struct sock*) ; 
 int /*<<< orphan*/  inet_twsk (struct sock*) ; 
 int /*<<< orphan*/  inet_twsk_put (int /*<<< orphan*/ ) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  nf_reset_ct (struct sk_buff*) ; 
 int /*<<< orphan*/  ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  reqsk_put (struct request_sock*) ; 
 int /*<<< orphan*/  sock_hold (struct sock*) ; 
 int /*<<< orphan*/  sock_put (struct sock*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  xfrm4_policy_check (struct sock*,int /*<<< orphan*/ ,struct sk_buff*) ; 

__attribute__((used)) static int dccp_v4_rcv(struct sk_buff *skb)
{
	const struct dccp_hdr *dh;
	const struct iphdr *iph;
	bool refcounted;
	struct sock *sk;
	int min_cov;

	/* Step 1: Check header basics */

	if (dccp_invalid_packet(skb))
		goto discard_it;

	iph = ip_hdr(skb);
	/* Step 1: If header checksum is incorrect, drop packet and return */
	if (dccp_v4_csum_finish(skb, iph->saddr, iph->daddr)) {
		DCCP_WARN("dropped packet with invalid checksum\n");
		goto discard_it;
	}

	dh = dccp_hdr(skb);

	DCCP_SKB_CB(skb)->dccpd_seq  = dccp_hdr_seq(dh);
	DCCP_SKB_CB(skb)->dccpd_type = dh->dccph_type;

	dccp_pr_debug("%8.8s src=%pI4@%-5d dst=%pI4@%-5d seq=%llu",
		      dccp_packet_name(dh->dccph_type),
		      &iph->saddr, ntohs(dh->dccph_sport),
		      &iph->daddr, ntohs(dh->dccph_dport),
		      (unsigned long long) DCCP_SKB_CB(skb)->dccpd_seq);

	if (dccp_packet_without_ack(skb)) {
		DCCP_SKB_CB(skb)->dccpd_ack_seq = DCCP_PKT_WITHOUT_ACK_SEQ;
		dccp_pr_debug_cat("\n");
	} else {
		DCCP_SKB_CB(skb)->dccpd_ack_seq = dccp_hdr_ack_seq(skb);
		dccp_pr_debug_cat(", ack=%llu\n", (unsigned long long)
				  DCCP_SKB_CB(skb)->dccpd_ack_seq);
	}

lookup:
	sk = __inet_lookup_skb(&dccp_hashinfo, skb, __dccp_hdr_len(dh),
			       dh->dccph_sport, dh->dccph_dport, 0, &refcounted);
	if (!sk) {
		dccp_pr_debug("failed to look up flow ID in table and "
			      "get corresponding socket\n");
		goto no_dccp_socket;
	}

	/*
	 * Step 2:
	 *	... or S.state == TIMEWAIT,
	 *		Generate Reset(No Connection) unless P.type == Reset
	 *		Drop packet and return
	 */
	if (sk->sk_state == DCCP_TIME_WAIT) {
		dccp_pr_debug("sk->sk_state == DCCP_TIME_WAIT: do_time_wait\n");
		inet_twsk_put(inet_twsk(sk));
		goto no_dccp_socket;
	}

	if (sk->sk_state == DCCP_NEW_SYN_RECV) {
		struct request_sock *req = inet_reqsk(sk);
		struct sock *nsk;

		sk = req->rsk_listener;
		if (unlikely(sk->sk_state != DCCP_LISTEN)) {
			inet_csk_reqsk_queue_drop_and_put(sk, req);
			goto lookup;
		}
		sock_hold(sk);
		refcounted = true;
		nsk = dccp_check_req(sk, skb, req);
		if (!nsk) {
			reqsk_put(req);
			goto discard_and_relse;
		}
		if (nsk == sk) {
			reqsk_put(req);
		} else if (dccp_child_process(sk, nsk, skb)) {
			dccp_v4_ctl_send_reset(sk, skb);
			goto discard_and_relse;
		} else {
			sock_put(sk);
			return 0;
		}
	}
	/*
	 * RFC 4340, sec. 9.2.1: Minimum Checksum Coverage
	 *	o if MinCsCov = 0, only packets with CsCov = 0 are accepted
	 *	o if MinCsCov > 0, also accept packets with CsCov >= MinCsCov
	 */
	min_cov = dccp_sk(sk)->dccps_pcrlen;
	if (dh->dccph_cscov && (min_cov == 0 || dh->dccph_cscov < min_cov))  {
		dccp_pr_debug("Packet CsCov %d does not satisfy MinCsCov %d\n",
			      dh->dccph_cscov, min_cov);
		/* FIXME: "Such packets SHOULD be reported using Data Dropped
		 *         options (Section 11.7) with Drop Code 0, Protocol
		 *         Constraints."                                     */
		goto discard_and_relse;
	}

	if (!xfrm4_policy_check(sk, XFRM_POLICY_IN, skb))
		goto discard_and_relse;
	nf_reset_ct(skb);

	return __sk_receive_skb(sk, skb, 1, dh->dccph_doff * 4, refcounted);

no_dccp_socket:
	if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
		goto discard_it;
	/*
	 * Step 2:
	 *	If no socket ...
	 *		Generate Reset(No Connection) unless P.type == Reset
	 *		Drop packet and return
	 */
	if (dh->dccph_type != DCCP_PKT_RESET) {
		DCCP_SKB_CB(skb)->dccpd_reset_code =
					DCCP_RESET_CODE_NO_CONNECTION;
		dccp_v4_ctl_send_reset(sk, skb);
	}

discard_it:
	kfree_skb(skb);
	return 0;

discard_and_relse:
	if (refcounted)
		sock_put(sk);
	goto discard_it;
}