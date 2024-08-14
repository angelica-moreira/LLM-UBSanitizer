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
struct mlxsw_sp_nve_mc_record {scalar_t__ num_entries; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp_nve_mc_record_destroy (struct mlxsw_sp_nve_mc_record*) ; 

__attribute__((used)) static void
mlxsw_sp_nve_mc_record_put(struct mlxsw_sp_nve_mc_record *mc_record)
{
	if (mc_record->num_entries != 0)
		return;

	mlxsw_sp_nve_mc_record_destroy(mc_record);
}