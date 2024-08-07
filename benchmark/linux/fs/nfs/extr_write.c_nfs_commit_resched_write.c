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
struct nfs_page {int /*<<< orphan*/  wb_page; } ;
struct nfs_commit_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __set_page_dirty_nobuffers (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
nfs_commit_resched_write(struct nfs_commit_info *cinfo,
		struct nfs_page *req)
{
	__set_page_dirty_nobuffers(req->wb_page);
}