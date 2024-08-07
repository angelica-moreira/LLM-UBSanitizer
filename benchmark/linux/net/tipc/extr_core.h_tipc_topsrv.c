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
struct tipc_topsrv {int dummy; } ;
struct net {int dummy; } ;
struct TYPE_2__ {struct tipc_topsrv* topsrv; } ;

/* Variables and functions */
 TYPE_1__* tipc_net (struct net*) ; 

__attribute__((used)) static inline struct tipc_topsrv *tipc_topsrv(struct net *net)
{
	return tipc_net(net)->topsrv;
}