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
typedef  int u32 ;
struct net_device {int dummy; } ;
struct cas {scalar_t__ lstate; } ;

/* Variables and functions */
 scalar_t__ link_up ; 
 struct cas* netdev_priv (struct net_device*) ; 

__attribute__((used)) static u32 cas_get_link(struct net_device *dev)
{
	struct cas *cp = netdev_priv(dev);
	return cp->lstate == link_up;
}