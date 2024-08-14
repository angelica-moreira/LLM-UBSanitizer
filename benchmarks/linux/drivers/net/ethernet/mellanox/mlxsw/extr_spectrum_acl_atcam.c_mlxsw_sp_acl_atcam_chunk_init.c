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
struct mlxsw_sp_acl_atcam_region {int /*<<< orphan*/  cregion; } ;
struct mlxsw_sp_acl_atcam_chunk {int /*<<< orphan*/  cchunk; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp_acl_ctcam_chunk_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 

void mlxsw_sp_acl_atcam_chunk_init(struct mlxsw_sp_acl_atcam_region *aregion,
				   struct mlxsw_sp_acl_atcam_chunk *achunk,
				   unsigned int priority)
{
	mlxsw_sp_acl_ctcam_chunk_init(&aregion->cregion, &achunk->cchunk,
				      priority);
}