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
 int ENOTSUPP ; 
#define  ETH_SS_PRIV_FLAGS 130 
#define  ETH_SS_STATS 129 
#define  ETH_SS_TEST 128 
 int IGC_PRIV_FLAGS_STR_LEN ; 
 int IGC_STATS_LEN ; 
 int IGC_TEST_LEN ; 

__attribute__((used)) static int igc_get_sset_count(struct net_device *netdev, int sset)
{
	switch (sset) {
	case ETH_SS_STATS:
		return IGC_STATS_LEN;
	case ETH_SS_TEST:
		return IGC_TEST_LEN;
	case ETH_SS_PRIV_FLAGS:
		return IGC_PRIV_FLAGS_STR_LEN;
	default:
		return -ENOTSUPP;
	}
}