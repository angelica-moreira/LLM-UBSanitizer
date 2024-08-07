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
struct nft_osf {int /*<<< orphan*/  dreg; int /*<<< orphan*/  flags; int /*<<< orphan*/  ttl; } ;
struct nft_expr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NFTA_OSF_DREG ; 
 int /*<<< orphan*/  NFTA_OSF_FLAGS ; 
 int /*<<< orphan*/  NFTA_OSF_TTL ; 
 scalar_t__ nft_dump_register (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nft_osf* nft_expr_priv (struct nft_expr const*) ; 
 scalar_t__ nla_put_be32 (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ nla_put_u8 (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ntohl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nft_osf_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	const struct nft_osf *priv = nft_expr_priv(expr);

	if (nla_put_u8(skb, NFTA_OSF_TTL, priv->ttl))
		goto nla_put_failure;

	if (nla_put_be32(skb, NFTA_OSF_FLAGS, ntohl(priv->flags)))
		goto nla_put_failure;

	if (nft_dump_register(skb, NFTA_OSF_DREG, priv->dreg))
		goto nla_put_failure;

	return 0;

nla_put_failure:
	return -1;
}