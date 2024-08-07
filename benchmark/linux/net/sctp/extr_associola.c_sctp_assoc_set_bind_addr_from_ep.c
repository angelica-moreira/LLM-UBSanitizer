#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  bind_addr; TYPE_5__* sk; } ;
struct TYPE_9__ {scalar_t__ ipv6_address; scalar_t__ ipv4_address; } ;
struct sctp_association {TYPE_2__* ep; TYPE_3__ base; TYPE_4__ peer; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  enum sctp_scope { ____Placeholder_sctp_scope } sctp_scope ;
struct TYPE_10__ {scalar_t__ sk_family; } ;
struct TYPE_6__ {int /*<<< orphan*/  bind_addr; } ;
struct TYPE_7__ {TYPE_1__ base; } ;

/* Variables and functions */
 scalar_t__ PF_INET6 ; 
 int SCTP_ADDR4_PEERSUPP ; 
 int SCTP_ADDR6_ALLOWED ; 
 int SCTP_ADDR6_PEERSUPP ; 
 int sctp_bind_addr_copy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sock_net (TYPE_5__*) ; 

int sctp_assoc_set_bind_addr_from_ep(struct sctp_association *asoc,
				     enum sctp_scope scope, gfp_t gfp)
{
	int flags;

	/* Use scoping rules to determine the subset of addresses from
	 * the endpoint.
	 */
	flags = (PF_INET6 == asoc->base.sk->sk_family) ? SCTP_ADDR6_ALLOWED : 0;
	if (asoc->peer.ipv4_address)
		flags |= SCTP_ADDR4_PEERSUPP;
	if (asoc->peer.ipv6_address)
		flags |= SCTP_ADDR6_PEERSUPP;

	return sctp_bind_addr_copy(sock_net(asoc->base.sk),
				   &asoc->base.bind_addr,
				   &asoc->ep->base.bind_addr,
				   scope, gfp, flags);
}