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
struct sis900_private {int /*<<< orphan*/  msg_enable; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct sis900_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void sis900_set_msglevel(struct net_device *net_dev, u32 value)
{
	struct sis900_private *sis_priv = netdev_priv(net_dev);
	sis_priv->msg_enable = value;
}