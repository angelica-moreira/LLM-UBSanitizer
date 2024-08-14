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
struct net_device {int mtu; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  vsockmon_is_valid_mtu (int) ; 

__attribute__((used)) static int vsockmon_change_mtu(struct net_device *dev, int new_mtu)
{
	if (!vsockmon_is_valid_mtu(new_mtu))
		return -EINVAL;

	dev->mtu = new_mtu;
	return 0;
}