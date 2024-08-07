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
typedef  int /*<<< orphan*/  uint32_t ;
struct net_device {int dummy; } ;
struct altera_tse_private {int /*<<< orphan*/  msg_enable; } ;

/* Variables and functions */
 struct altera_tse_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void tse_set_msglevel(struct net_device *dev, uint32_t data)
{
	struct altera_tse_private *priv = netdev_priv(dev);
	priv->msg_enable = data;
}