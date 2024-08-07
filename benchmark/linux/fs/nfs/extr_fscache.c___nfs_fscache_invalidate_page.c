#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct page {TYPE_1__* mapping; } ;
struct inode {int dummy; } ;
struct fscache_cookie {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  host; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  FSCACHE ; 
 int /*<<< orphan*/  NFSIOS_FSCACHE_PAGES_UNCACHED ; 
 int /*<<< orphan*/  NFS_I (struct inode*) ; 
 int /*<<< orphan*/  PageLocked (struct page*) ; 
 int /*<<< orphan*/  dfprintk (int /*<<< orphan*/ ,char*,struct fscache_cookie*,struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fscache_uncache_page (struct fscache_cookie*,struct page*) ; 
 int /*<<< orphan*/  fscache_wait_on_page_write (struct fscache_cookie*,struct page*) ; 
 struct fscache_cookie* nfs_i_fscache (struct inode*) ; 
 int /*<<< orphan*/  nfs_inc_fscache_stats (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void __nfs_fscache_invalidate_page(struct page *page, struct inode *inode)
{
	struct fscache_cookie *cookie = nfs_i_fscache(inode);

	BUG_ON(!cookie);

	dfprintk(FSCACHE, "NFS: fscache invalidatepage (0x%p/0x%p/0x%p)\n",
		 cookie, page, NFS_I(inode));

	fscache_wait_on_page_write(cookie, page);

	BUG_ON(!PageLocked(page));
	fscache_uncache_page(cookie, page);
	nfs_inc_fscache_stats(page->mapping->host,
			      NFSIOS_FSCACHE_PAGES_UNCACHED);
}