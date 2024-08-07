#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct nfs_pageio_descriptor {TYPE_1__* pg_lseg; int /*<<< orphan*/  pg_inode; int /*<<< orphan*/ * pg_dreq; } ;
struct nfs_page {int /*<<< orphan*/  wb_index; } ;
struct TYPE_3__ {int /*<<< orphan*/  pls_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  NFS_LSEG_UNAVAILABLE ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  is_aligned_req (struct nfs_pageio_descriptor*,struct nfs_page*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nfs_dreq_bytes_left (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nfs_pageio_reset_write_mds (struct nfs_pageio_descriptor*) ; 
 int /*<<< orphan*/  pnfs_error_mark_layout_for_return (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  pnfs_generic_pg_init_write (struct nfs_pageio_descriptor*,struct nfs_page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnfs_num_cont_bytes (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnfs_set_lo_fail (TYPE_1__*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
bl_pg_init_write(struct nfs_pageio_descriptor *pgio, struct nfs_page *req)
{
	u64 wb_size;

	if (!is_aligned_req(pgio, req, PAGE_SIZE, true)) {
		nfs_pageio_reset_write_mds(pgio);
		return;
	}

	if (pgio->pg_dreq == NULL)
		wb_size = pnfs_num_cont_bytes(pgio->pg_inode,
					      req->wb_index);
	else
		wb_size = nfs_dreq_bytes_left(pgio->pg_dreq);

	pnfs_generic_pg_init_write(pgio, req, wb_size);

	if (pgio->pg_lseg &&
		test_bit(NFS_LSEG_UNAVAILABLE, &pgio->pg_lseg->pls_flags)) {

		pnfs_error_mark_layout_for_return(pgio->pg_inode, pgio->pg_lseg);
		pnfs_set_lo_fail(pgio->pg_lseg);
		nfs_pageio_reset_write_mds(pgio);
	}
}