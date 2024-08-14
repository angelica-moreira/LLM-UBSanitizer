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
struct nfs_pgio_header {int /*<<< orphan*/  flags; int /*<<< orphan*/  lseg; int /*<<< orphan*/  task; } ;

/* Variables and functions */
 int /*<<< orphan*/  NFS_IOHDR_RESEND_MDS ; 
 int /*<<< orphan*/  NFS_IOHDR_RESEND_PNFS ; 
 int /*<<< orphan*/  ff_layout_read_record_layoutstats_done (int /*<<< orphan*/ *,struct nfs_pgio_header*) ; 
 int /*<<< orphan*/  ff_layout_reset_read (struct nfs_pgio_header*) ; 
 int /*<<< orphan*/  ff_layout_send_layouterror (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnfs_generic_rw_release (void*) ; 
 int /*<<< orphan*/  pnfs_read_resend_pnfs (struct nfs_pgio_header*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ff_layout_read_release(void *data)
{
	struct nfs_pgio_header *hdr = data;

	ff_layout_read_record_layoutstats_done(&hdr->task, hdr);
	if (test_bit(NFS_IOHDR_RESEND_PNFS, &hdr->flags)) {
		ff_layout_send_layouterror(hdr->lseg);
		pnfs_read_resend_pnfs(hdr);
	} else if (test_bit(NFS_IOHDR_RESEND_MDS, &hdr->flags))
		ff_layout_reset_read(hdr);
	pnfs_generic_rw_release(data);
}