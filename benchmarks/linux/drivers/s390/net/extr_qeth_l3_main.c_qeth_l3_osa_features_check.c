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
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  netdev_features_t ;

/* Variables and functions */
 int /*<<< orphan*/  NETIF_F_HW_VLAN_CTAG_TX ; 
 int /*<<< orphan*/  qeth_features_check (struct sk_buff*,struct net_device*,int /*<<< orphan*/ ) ; 
 int qeth_get_ip_version (struct sk_buff*) ; 

__attribute__((used)) static netdev_features_t qeth_l3_osa_features_check(struct sk_buff *skb,
						    struct net_device *dev,
						    netdev_features_t features)
{
	if (qeth_get_ip_version(skb) != 4)
		features &= ~NETIF_F_HW_VLAN_CTAG_TX;
	return qeth_features_check(skb, dev, features);
}