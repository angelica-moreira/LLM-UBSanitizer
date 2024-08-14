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
typedef  union mlxsw_sp_l3addr {int dummy; } mlxsw_sp_l3addr ;
struct mlxsw_sp_nve_mc_record {int dummy; } ;
struct mlxsw_sp_nve_mc_list {int dummy; } ;
struct mlxsw_sp_nve_mc_entry {int dummy; } ;
struct mlxsw_sp {int dummy; } ;
typedef  enum mlxsw_sp_l3proto { ____Placeholder_mlxsw_sp_l3proto } mlxsw_sp_l3proto ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp_nve_mc_record_entry_del (struct mlxsw_sp_nve_mc_record*,struct mlxsw_sp_nve_mc_entry*) ; 
 struct mlxsw_sp_nve_mc_record* mlxsw_sp_nve_mc_record_find (struct mlxsw_sp_nve_mc_list*,int,union mlxsw_sp_l3addr*,struct mlxsw_sp_nve_mc_entry**) ; 
 int /*<<< orphan*/  mlxsw_sp_nve_mc_record_put (struct mlxsw_sp_nve_mc_record*) ; 

__attribute__((used)) static void mlxsw_sp_nve_mc_list_ip_del(struct mlxsw_sp *mlxsw_sp,
					struct mlxsw_sp_nve_mc_list *mc_list,
					enum mlxsw_sp_l3proto proto,
					union mlxsw_sp_l3addr *addr)
{
	struct mlxsw_sp_nve_mc_record *mc_record;
	struct mlxsw_sp_nve_mc_entry *mc_entry;

	mc_record = mlxsw_sp_nve_mc_record_find(mc_list, proto, addr,
						&mc_entry);
	if (!mc_record)
		return;

	mlxsw_sp_nve_mc_record_entry_del(mc_record, mc_entry);
	mlxsw_sp_nve_mc_record_put(mc_record);
}