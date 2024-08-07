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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int ETH_GSTRING_LEN ; 
#define  ETH_SS_PRIV_FLAGS 130 
#define  ETH_SS_STATS 129 
#define  ETH_SS_TEST 128 
 int I40E_TEST_LEN ; 
 int /*<<< orphan*/  i40e_get_priv_flag_strings (struct net_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i40e_get_stat_strings (struct net_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i40e_gstrings_test ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void i40e_get_strings(struct net_device *netdev, u32 stringset,
			     u8 *data)
{
	switch (stringset) {
	case ETH_SS_TEST:
		memcpy(data, i40e_gstrings_test,
		       I40E_TEST_LEN * ETH_GSTRING_LEN);
		break;
	case ETH_SS_STATS:
		i40e_get_stat_strings(netdev, data);
		break;
	case ETH_SS_PRIV_FLAGS:
		i40e_get_priv_flag_strings(netdev, data);
		break;
	default:
		break;
	}
}