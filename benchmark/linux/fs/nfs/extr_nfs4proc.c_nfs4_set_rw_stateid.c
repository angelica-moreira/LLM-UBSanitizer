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
struct nfs_open_context {int /*<<< orphan*/  state; } ;
struct nfs_lock_context {int dummy; } ;
typedef  int /*<<< orphan*/  nfs4_stateid ;
typedef  int /*<<< orphan*/  fmode_t ;

/* Variables and functions */
 int nfs4_select_rw_stateid (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nfs_lock_context const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int nfs4_set_rw_stateid(nfs4_stateid *stateid,
		const struct nfs_open_context *ctx,
		const struct nfs_lock_context *l_ctx,
		fmode_t fmode)
{
	return nfs4_select_rw_stateid(ctx->state, fmode, l_ctx, stateid, NULL);
}