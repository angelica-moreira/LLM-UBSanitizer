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
struct mlxsw_sp1_acl_tcam_chunk {int /*<<< orphan*/  cchunk; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp_acl_ctcam_chunk_fini (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mlxsw_sp1_acl_tcam_chunk_fini(void *chunk_priv)
{
	struct mlxsw_sp1_acl_tcam_chunk *chunk = chunk_priv;

	mlxsw_sp_acl_ctcam_chunk_fini(&chunk->cchunk);
}