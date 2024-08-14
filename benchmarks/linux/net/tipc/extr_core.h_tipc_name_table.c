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
struct net {int dummy; } ;
struct name_table {int dummy; } ;
struct TYPE_2__ {struct name_table* nametbl; } ;

/* Variables and functions */
 TYPE_1__* tipc_net (struct net*) ; 

__attribute__((used)) static inline struct name_table *tipc_name_table(struct net *net)
{
	return tipc_net(net)->nametbl;
}