#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
struct sock {scalar_t__ sk_type; } ;
struct sk_buff {scalar_t__ len; int /*<<< orphan*/  protocol; TYPE_1__* dev; } ;
struct iucv_sock {int msglimit; int /*<<< orphan*/  msg_recv; int /*<<< orphan*/  send_skb_q; TYPE_1__* hs_dev; struct iucv_message* src_name; struct iucv_message* src_user_id; struct iucv_message* dst_name; struct iucv_message* dst_user_id; } ;
struct iucv_message {int dummy; } ;
struct af_iucv_trans_hdr {int version; scalar_t__ flags; int window; int /*<<< orphan*/  iucv_hdr; int /*<<< orphan*/ * srcAppName; int /*<<< orphan*/ * srcUserID; int /*<<< orphan*/ * destAppName; int /*<<< orphan*/ * destUserID; int /*<<< orphan*/  magic; } ;
struct TYPE_3__ {int flags; scalar_t__ mtu; } ;

/* Variables and functions */
 scalar_t__ AF_IUCV_FLAG_SYN ; 
 scalar_t__ AF_IUCV_FLAG_WIN ; 
 int /*<<< orphan*/  ASCEBC (int /*<<< orphan*/ *,int) ; 
 int EMSGSIZE ; 
 int ENETDOWN ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETH_P_AF_IUCV ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int IFF_UP ; 
 scalar_t__ SOCK_SEQPACKET ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __skb_header_release (struct sk_buff*) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_sub (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_to_be16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_hard_header (struct sk_buff*,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 int dev_queue_xmit (struct sk_buff*) ; 
 struct iucv_sock* iucv_sk (struct sock*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct iucv_message*,int) ; 
 int /*<<< orphan*/  memset (struct af_iucv_trans_hdr*,int /*<<< orphan*/ ,int) ; 
 int net_xmit_eval (int) ; 
 int /*<<< orphan*/  netif_carrier_ok (TYPE_1__*) ; 
 struct sk_buff* skb_clone (struct sk_buff*,int /*<<< orphan*/ ) ; 
 struct af_iucv_trans_hdr* skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_trim (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_unlink (struct sk_buff*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int afiucv_hs_send(struct iucv_message *imsg, struct sock *sock,
		   struct sk_buff *skb, u8 flags)
{
	struct iucv_sock *iucv = iucv_sk(sock);
	struct af_iucv_trans_hdr *phs_hdr;
	struct sk_buff *nskb;
	int err, confirm_recv = 0;

	phs_hdr = skb_push(skb, sizeof(*phs_hdr));
	memset(phs_hdr, 0, sizeof(*phs_hdr));
	skb_reset_network_header(skb);

	phs_hdr->magic = ETH_P_AF_IUCV;
	phs_hdr->version = 1;
	phs_hdr->flags = flags;
	if (flags == AF_IUCV_FLAG_SYN)
		phs_hdr->window = iucv->msglimit;
	else if ((flags == AF_IUCV_FLAG_WIN) || !flags) {
		confirm_recv = atomic_read(&iucv->msg_recv);
		phs_hdr->window = confirm_recv;
		if (confirm_recv)
			phs_hdr->flags = phs_hdr->flags | AF_IUCV_FLAG_WIN;
	}
	memcpy(phs_hdr->destUserID, iucv->dst_user_id, 8);
	memcpy(phs_hdr->destAppName, iucv->dst_name, 8);
	memcpy(phs_hdr->srcUserID, iucv->src_user_id, 8);
	memcpy(phs_hdr->srcAppName, iucv->src_name, 8);
	ASCEBC(phs_hdr->destUserID, sizeof(phs_hdr->destUserID));
	ASCEBC(phs_hdr->destAppName, sizeof(phs_hdr->destAppName));
	ASCEBC(phs_hdr->srcUserID, sizeof(phs_hdr->srcUserID));
	ASCEBC(phs_hdr->srcAppName, sizeof(phs_hdr->srcAppName));
	if (imsg)
		memcpy(&phs_hdr->iucv_hdr, imsg, sizeof(struct iucv_message));

	skb->dev = iucv->hs_dev;
	if (!skb->dev) {
		err = -ENODEV;
		goto err_free;
	}

	dev_hard_header(skb, skb->dev, ETH_P_AF_IUCV, NULL, NULL, skb->len);

	if (!(skb->dev->flags & IFF_UP) || !netif_carrier_ok(skb->dev)) {
		err = -ENETDOWN;
		goto err_free;
	}
	if (skb->len > skb->dev->mtu) {
		if (sock->sk_type == SOCK_SEQPACKET) {
			err = -EMSGSIZE;
			goto err_free;
		}
		skb_trim(skb, skb->dev->mtu);
	}
	skb->protocol = cpu_to_be16(ETH_P_AF_IUCV);

	__skb_header_release(skb);
	nskb = skb_clone(skb, GFP_ATOMIC);
	if (!nskb) {
		err = -ENOMEM;
		goto err_free;
	}

	skb_queue_tail(&iucv->send_skb_q, nskb);
	err = dev_queue_xmit(skb);
	if (net_xmit_eval(err)) {
		skb_unlink(nskb, &iucv->send_skb_q);
		kfree_skb(nskb);
	} else {
		atomic_sub(confirm_recv, &iucv->msg_recv);
		WARN_ON(atomic_read(&iucv->msg_recv) < 0);
	}
	return net_xmit_eval(err);

err_free:
	kfree_skb(skb);
	return err;
}