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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct bonding {int dummy; } ;
struct ad_info {int /*<<< orphan*/  partner_system; } ;
typedef  int ssize_t ;

/* Variables and functions */
 scalar_t__ BOND_MODE (struct bonding*) ; 
 scalar_t__ BOND_MODE_8023AD ; 
 int /*<<< orphan*/  CAP_NET_ADMIN ; 
 int /*<<< orphan*/  bond_3ad_get_active_agg_info (struct bonding*,struct ad_info*) ; 
 scalar_t__ capable (int /*<<< orphan*/ ) ; 
 int sprintf (char*,char*,int /*<<< orphan*/ ) ; 
 struct bonding* to_bond (struct device*) ; 

__attribute__((used)) static ssize_t bonding_show_ad_partner_mac(struct device *d,
					   struct device_attribute *attr,
					   char *buf)
{
	int count = 0;
	struct bonding *bond = to_bond(d);

	if (BOND_MODE(bond) == BOND_MODE_8023AD && capable(CAP_NET_ADMIN)) {
		struct ad_info ad_info;
		if (!bond_3ad_get_active_agg_info(bond, &ad_info))
			count = sprintf(buf, "%pM\n", ad_info.partner_system);
	}

	return count;
}