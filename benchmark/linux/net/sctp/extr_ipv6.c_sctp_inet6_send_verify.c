#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  sin6_scope_id; int /*<<< orphan*/  sin6_addr; } ;
struct TYPE_8__ {scalar_t__ sa_family; } ;
union sctp_addr {TYPE_2__ v6; TYPE_4__ sa; } ;
struct TYPE_5__ {int /*<<< orphan*/  sk; } ;
struct sctp_sock {TYPE_3__* pf; TYPE_1__ inet; } ;
struct sctp_af {int dummy; } ;
struct net_device {int dummy; } ;
struct TYPE_7__ {struct sctp_af* af; } ;

/* Variables and functions */
 scalar_t__ AF_INET6 ; 
 int IPV6_ADDR_LINKLOCAL ; 
 struct net_device* dev_get_by_index_rcu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ipv6_addr_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 struct sctp_af* sctp_get_af_specific (scalar_t__) ; 
 int /*<<< orphan*/  sock_net (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int sctp_inet6_send_verify(struct sctp_sock *opt, union sctp_addr *addr)
{
	struct sctp_af *af = NULL;

	/* ASSERT: address family has already been verified. */
	if (addr->sa.sa_family != AF_INET6)
		af = sctp_get_af_specific(addr->sa.sa_family);
	else {
		int type = ipv6_addr_type(&addr->v6.sin6_addr);
		struct net_device *dev;

		if (type & IPV6_ADDR_LINKLOCAL) {
			if (!addr->v6.sin6_scope_id)
				return 0;
			rcu_read_lock();
			dev = dev_get_by_index_rcu(sock_net(&opt->inet.sk),
						   addr->v6.sin6_scope_id);
			rcu_read_unlock();
			if (!dev)
				return 0;
		}
		af = opt->pf->af;
	}

	return af != NULL;
}