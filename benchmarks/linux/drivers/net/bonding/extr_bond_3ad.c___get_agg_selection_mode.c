#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct port {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  ad_select; } ;
struct bonding {TYPE_1__ params; } ;

/* Variables and functions */
 int /*<<< orphan*/  BOND_AD_STABLE ; 
 struct bonding* __get_bond_by_port (struct port*) ; 

__attribute__((used)) static inline u32 __get_agg_selection_mode(struct port *port)
{
	struct bonding *bond = __get_bond_by_port(port);

	if (bond == NULL)
		return BOND_AD_STABLE;

	return bond->params.ad_select;
}