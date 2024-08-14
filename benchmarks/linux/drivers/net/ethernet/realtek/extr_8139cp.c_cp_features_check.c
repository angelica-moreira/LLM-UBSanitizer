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
typedef  int /*<<< orphan*/  netdev_features_t ;
struct TYPE_2__ {scalar_t__ gso_size; } ;

/* Variables and functions */
 scalar_t__ MSSMask ; 
 int /*<<< orphan*/  NETIF_F_TSO ; 
 TYPE_1__* skb_shinfo (struct sk_buff*) ; 
 int /*<<< orphan*/  vlan_features_check (struct sk_buff*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static netdev_features_t cp_features_check(struct sk_buff *skb,
					   struct net_device *dev,
					   netdev_features_t features)
{
	if (skb_shinfo(skb)->gso_size > MSSMask)
		features &= ~NETIF_F_TSO;

	return vlan_features_check(skb, features);
}