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
typedef  int u32 ;
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct request_sock {int dummy; } ;
struct dst_entry {int dummy; } ;
struct dccp_request_sock {int /*<<< orphan*/  dreq_service; int /*<<< orphan*/  dreq_gsr; int /*<<< orphan*/  dreq_gss; } ;
struct dccp_hdr_response {int dummy; } ;
struct dccp_hdr_ext {int dummy; } ;
struct dccp_hdr {int dccph_doff; int dccph_x; void* dccph_type; int /*<<< orphan*/  dccph_dport; int /*<<< orphan*/  dccph_sport; } ;
struct TYPE_6__ {int const dccpd_opt_len; int /*<<< orphan*/  dccpd_seq; void* dccpd_type; } ;
struct TYPE_5__ {int /*<<< orphan*/  dccph_resp_service; } ;
struct TYPE_4__ {int acked; int /*<<< orphan*/  ir_rmt_port; int /*<<< orphan*/  ir_num; } ;

/* Variables and functions */
 int /*<<< orphan*/  DCCP_INC_STATS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DCCP_MIB_OUTSEGS ; 
 void* DCCP_PKT_RESPONSE ; 
 TYPE_3__* DCCP_SKB_CB (struct sk_buff*) ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  MAX_DCCP_HEADER ; 
 int /*<<< orphan*/  dccp_csum_outgoing (struct sk_buff*) ; 
 scalar_t__ dccp_feat_server_ccid_dependencies (struct dccp_request_sock*) ; 
 int /*<<< orphan*/  dccp_hdr_ack_bits (struct sk_buff*) ; 
 TYPE_2__* dccp_hdr_response (struct sk_buff*) ; 
 int /*<<< orphan*/  dccp_hdr_set_ack (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dccp_hdr_set_seq (struct dccp_hdr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dccp_inc_seqno (int /*<<< orphan*/ *) ; 
 scalar_t__ dccp_insert_options_rsk (struct dccp_request_sock*,struct sk_buff*) ; 
 struct dccp_request_sock* dccp_rsk (struct request_sock*) ; 
 struct dccp_hdr* dccp_zeroed_hdr (struct sk_buff*,int const) ; 
 int /*<<< orphan*/  dst_clone (struct dst_entry*) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 TYPE_1__* inet_rsk (struct request_sock*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_dst_set (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,int /*<<< orphan*/ ) ; 
 struct sk_buff* sock_wmalloc (struct sock*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

struct sk_buff *dccp_make_response(const struct sock *sk, struct dst_entry *dst,
				   struct request_sock *req)
{
	struct dccp_hdr *dh;
	struct dccp_request_sock *dreq;
	const u32 dccp_header_size = sizeof(struct dccp_hdr) +
				     sizeof(struct dccp_hdr_ext) +
				     sizeof(struct dccp_hdr_response);
	struct sk_buff *skb;

	/* sk is marked const to clearly express we dont hold socket lock.
	 * sock_wmalloc() will atomically change sk->sk_wmem_alloc,
	 * it is safe to promote sk to non const.
	 */
	skb = sock_wmalloc((struct sock *)sk, MAX_DCCP_HEADER, 1,
			   GFP_ATOMIC);
	if (!skb)
		return NULL;

	skb_reserve(skb, MAX_DCCP_HEADER);

	skb_dst_set(skb, dst_clone(dst));

	dreq = dccp_rsk(req);
	if (inet_rsk(req)->acked)	/* increase GSS upon retransmission */
		dccp_inc_seqno(&dreq->dreq_gss);
	DCCP_SKB_CB(skb)->dccpd_type = DCCP_PKT_RESPONSE;
	DCCP_SKB_CB(skb)->dccpd_seq  = dreq->dreq_gss;

	/* Resolve feature dependencies resulting from choice of CCID */
	if (dccp_feat_server_ccid_dependencies(dreq))
		goto response_failed;

	if (dccp_insert_options_rsk(dreq, skb))
		goto response_failed;

	/* Build and checksum header */
	dh = dccp_zeroed_hdr(skb, dccp_header_size);

	dh->dccph_sport	= htons(inet_rsk(req)->ir_num);
	dh->dccph_dport	= inet_rsk(req)->ir_rmt_port;
	dh->dccph_doff	= (dccp_header_size +
			   DCCP_SKB_CB(skb)->dccpd_opt_len) / 4;
	dh->dccph_type	= DCCP_PKT_RESPONSE;
	dh->dccph_x	= 1;
	dccp_hdr_set_seq(dh, dreq->dreq_gss);
	dccp_hdr_set_ack(dccp_hdr_ack_bits(skb), dreq->dreq_gsr);
	dccp_hdr_response(skb)->dccph_resp_service = dreq->dreq_service;

	dccp_csum_outgoing(skb);

	/* We use `acked' to remember that a Response was already sent. */
	inet_rsk(req)->acked = 1;
	DCCP_INC_STATS(DCCP_MIB_OUTSEGS);
	return skb;
response_failed:
	kfree_skb(skb);
	return NULL;
}