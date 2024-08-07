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
 int CP_NUM_STATS ; 
 int EOPNOTSUPP ; 
#define  ETH_SS_STATS 128 

__attribute__((used)) static int cp_get_sset_count (struct net_device *dev, int sset)
{
	switch (sset) {
	case ETH_SS_STATS:
		return CP_NUM_STATS;
	default:
		return -EOPNOTSUPP;
	}
}