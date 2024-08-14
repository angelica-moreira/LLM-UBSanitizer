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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct jme_adapter {int /*<<< orphan*/  msg_enable; } ;

/* Variables and functions */
 struct jme_adapter* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void
jme_set_msglevel(struct net_device *netdev, u32 value)
{
	struct jme_adapter *jme = netdev_priv(netdev);
	jme->msg_enable = value;
}