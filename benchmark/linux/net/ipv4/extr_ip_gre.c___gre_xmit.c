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
struct sk_buff {int dummy; } ;
struct net_device {int dummy; } ;
struct iphdr {int /*<<< orphan*/  protocol; } ;
struct TYPE_2__ {int o_flags; int /*<<< orphan*/  o_key; } ;
struct ip_tunnel {int /*<<< orphan*/  o_seqno; TYPE_1__ parms; int /*<<< orphan*/  tun_hlen; } ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int TUNNEL_SEQ ; 
 int /*<<< orphan*/  gre_build_header (struct sk_buff*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ip_tunnel_xmit (struct sk_buff*,struct net_device*,struct iphdr const*,int /*<<< orphan*/ ) ; 
 struct ip_tunnel* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void __gre_xmit(struct sk_buff *skb, struct net_device *dev,
		       const struct iphdr *tnl_params,
		       __be16 proto)
{
	struct ip_tunnel *tunnel = netdev_priv(dev);

	if (tunnel->parms.o_flags & TUNNEL_SEQ)
		tunnel->o_seqno++;

	/* Push GRE header. */
	gre_build_header(skb, tunnel->tun_hlen,
			 tunnel->parms.o_flags, proto, tunnel->parms.o_key,
			 htonl(tunnel->o_seqno));

	ip_tunnel_xmit(skb, dev, tnl_params, tnl_params->protocol);
}