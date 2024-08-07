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
struct tcphdr {scalar_t__ check; } ;
struct sk_buff {scalar_t__ ip_summed; } ;
struct iphdr {int /*<<< orphan*/  daddr; int /*<<< orphan*/  saddr; } ;
typedef  int /*<<< orphan*/  netdev_features_t ;
struct TYPE_2__ {int gso_type; } ;

/* Variables and functions */
 scalar_t__ CHECKSUM_PARTIAL ; 
 int /*<<< orphan*/  EINVAL ; 
 struct sk_buff* ERR_PTR (int /*<<< orphan*/ ) ; 
 int SKB_GSO_TCPV4 ; 
 int /*<<< orphan*/  __tcp_v4_send_check (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 TYPE_1__* skb_shinfo (struct sk_buff*) ; 
 struct sk_buff* tcp_gso_segment (struct sk_buff*,int /*<<< orphan*/ ) ; 
 struct tcphdr* tcp_hdr (struct sk_buff*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static struct sk_buff *tcp4_gso_segment(struct sk_buff *skb,
					netdev_features_t features)
{
	if (!(skb_shinfo(skb)->gso_type & SKB_GSO_TCPV4))
		return ERR_PTR(-EINVAL);

	if (!pskb_may_pull(skb, sizeof(struct tcphdr)))
		return ERR_PTR(-EINVAL);

	if (unlikely(skb->ip_summed != CHECKSUM_PARTIAL)) {
		const struct iphdr *iph = ip_hdr(skb);
		struct tcphdr *th = tcp_hdr(skb);

		/* Set up checksum pseudo header, usually expect stack to
		 * have done this already.
		 */

		th->check = 0;
		skb->ip_summed = CHECKSUM_PARTIAL;
		__tcp_v4_send_check(skb, iph->saddr, iph->daddr);
	}

	return tcp_gso_segment(skb, features);
}