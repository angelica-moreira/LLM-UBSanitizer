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
struct TYPE_3__ {int /*<<< orphan*/  state; } ;
struct TYPE_4__ {TYPE_1__ u; } ;
struct pfkey_sock {TYPE_2__ dump; int /*<<< orphan*/  sk; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dump_sa ; 
 struct net* sock_net (int /*<<< orphan*/ *) ; 
 int xfrm_state_walk (struct net*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static int pfkey_dump_sa(struct pfkey_sock *pfk)
{
	struct net *net = sock_net(&pfk->sk);
	return xfrm_state_walk(net, &pfk->dump.u.state, dump_sa, (void *) pfk);
}