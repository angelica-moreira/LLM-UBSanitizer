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
struct net_device {int dummy; } ;
struct libipw_device {void* priv; } ;

/* Variables and functions */
 scalar_t__ netdev_priv (struct net_device*) ; 

__attribute__((used)) static inline void *libipw_priv(struct net_device *dev)
{
	return ((struct libipw_device *)netdev_priv(dev))->priv;
}