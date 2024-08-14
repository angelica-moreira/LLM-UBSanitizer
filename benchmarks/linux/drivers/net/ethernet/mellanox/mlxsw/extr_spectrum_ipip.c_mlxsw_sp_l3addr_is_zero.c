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
union mlxsw_sp_l3addr {int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  naddr ;

/* Variables and functions */
 int /*<<< orphan*/  memcmp (union mlxsw_sp_l3addr*,union mlxsw_sp_l3addr*,int) ; 

bool mlxsw_sp_l3addr_is_zero(union mlxsw_sp_l3addr addr)
{
	union mlxsw_sp_l3addr naddr = {0};

	return !memcmp(&addr, &naddr, sizeof(naddr));
}