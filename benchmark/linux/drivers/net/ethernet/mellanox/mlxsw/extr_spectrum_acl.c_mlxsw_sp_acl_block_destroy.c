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
struct mlxsw_sp_acl_block {int /*<<< orphan*/  binding_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  kfree (struct mlxsw_sp_acl_block*) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 

void mlxsw_sp_acl_block_destroy(struct mlxsw_sp_acl_block *block)
{
	WARN_ON(!list_empty(&block->binding_list));
	kfree(block);
}