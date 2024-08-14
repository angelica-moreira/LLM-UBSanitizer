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

/* Variables and functions */
 int __fm10k_uc_sync (struct net_device*,unsigned char const*,int) ; 

__attribute__((used)) static int fm10k_uc_unsync(struct net_device *dev,
			   const unsigned char *addr)
{
	return __fm10k_uc_sync(dev, addr, false);
}