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
struct mlxsw_sp_acl_erp_table {int /*<<< orphan*/ * ops; } ;
struct mlxsw_sp_acl_erp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  erp_no_mask_ops ; 
 int /*<<< orphan*/  mlxsw_sp_acl_erp_generic_destroy (struct mlxsw_sp_acl_erp*) ; 

__attribute__((used)) static void
mlxsw_sp_acl_erp_first_mask_destroy(struct mlxsw_sp_acl_erp_table *erp_table,
				    struct mlxsw_sp_acl_erp *erp)
{
	mlxsw_sp_acl_erp_generic_destroy(erp);
	erp_table->ops = &erp_no_mask_ops;
}