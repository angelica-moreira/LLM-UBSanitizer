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

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp_acl_erp_rehash_hints_put (void*) ; 

void mlxsw_sp_acl_atcam_rehash_hints_put(void *hints_priv)
{
	mlxsw_sp_acl_erp_rehash_hints_put(hints_priv);
}