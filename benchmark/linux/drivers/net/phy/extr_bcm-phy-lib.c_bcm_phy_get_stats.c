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
typedef  int /*<<< orphan*/  u64 ;
struct phy_device {int dummy; } ;
struct ethtool_stats {int dummy; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcm_phy_get_stat (struct phy_device*,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  bcm_phy_hw_stats ; 

void bcm_phy_get_stats(struct phy_device *phydev, u64 *shadow,
		       struct ethtool_stats *stats, u64 *data)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(bcm_phy_hw_stats); i++)
		data[i] = bcm_phy_get_stat(phydev, shadow, i);
}