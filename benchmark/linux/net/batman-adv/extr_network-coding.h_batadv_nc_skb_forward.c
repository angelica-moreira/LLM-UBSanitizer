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
struct batadv_neigh_node {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline bool batadv_nc_skb_forward(struct sk_buff *skb,
					 struct batadv_neigh_node *neigh_node)
{
	return false;
}