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
struct net {int dummy; } ;

/* Variables and functions */
 int TIPC_NODE_SCOPE ; 
 int tipc_own_addr (struct net*) ; 

__attribute__((used)) static inline int tipc_scope2node(struct net *net, int sc)
{
	return sc != TIPC_NODE_SCOPE ? 0 : tipc_own_addr(net);
}