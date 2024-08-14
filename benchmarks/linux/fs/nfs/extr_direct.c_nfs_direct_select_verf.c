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
struct nfs_writeverf {int dummy; } ;
struct TYPE_3__ {int nbuckets; TYPE_2__* buckets; } ;
struct nfs_direct_req {TYPE_1__ ds_cinfo; struct nfs_writeverf verf; } ;
struct nfs_client {int dummy; } ;
struct TYPE_4__ {struct nfs_writeverf direct_verf; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 

__attribute__((used)) static struct nfs_writeverf *
nfs_direct_select_verf(struct nfs_direct_req *dreq,
		       struct nfs_client *ds_clp,
		       int commit_idx)
{
	struct nfs_writeverf *verfp = &dreq->verf;

#ifdef CONFIG_NFS_V4_1
	/*
	 * pNFS is in use, use the DS verf except commit_through_mds is set
	 * for layout segment where nbuckets is zero.
	 */
	if (ds_clp && dreq->ds_cinfo.nbuckets > 0) {
		if (commit_idx >= 0 && commit_idx < dreq->ds_cinfo.nbuckets)
			verfp = &dreq->ds_cinfo.buckets[commit_idx].direct_verf;
		else
			WARN_ON_ONCE(1);
	}
#endif
	return verfp;
}