#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * promisc_grp; int /*<<< orphan*/ * allmulti_grp; int /*<<< orphan*/ * addr_grp; int /*<<< orphan*/ * fdb; } ;
struct TYPE_4__ {TYPE_1__ legacy; } ;
struct mlx5_eswitch {TYPE_2__ fdb_table; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  esw_debug (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mlx5_destroy_flow_group (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mlx5_destroy_flow_table (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void esw_destroy_legacy_fdb_table(struct mlx5_eswitch *esw)
{
	esw_debug(esw->dev, "Destroy FDB Table\n");
	if (!esw->fdb_table.legacy.fdb)
		return;

	if (esw->fdb_table.legacy.promisc_grp)
		mlx5_destroy_flow_group(esw->fdb_table.legacy.promisc_grp);
	if (esw->fdb_table.legacy.allmulti_grp)
		mlx5_destroy_flow_group(esw->fdb_table.legacy.allmulti_grp);
	if (esw->fdb_table.legacy.addr_grp)
		mlx5_destroy_flow_group(esw->fdb_table.legacy.addr_grp);
	mlx5_destroy_flow_table(esw->fdb_table.legacy.fdb);

	esw->fdb_table.legacy.fdb = NULL;
	esw->fdb_table.legacy.addr_grp = NULL;
	esw->fdb_table.legacy.allmulti_grp = NULL;
	esw->fdb_table.legacy.promisc_grp = NULL;
}