#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct page {int /*<<< orphan*/  flags; int /*<<< orphan*/  index; } ;
struct fscache_retrieval {int dummy; } ;
struct TYPE_6__ {struct page* private; } ;
struct cachefiles_one_read {int /*<<< orphan*/  op; TYPE_2__ monitor; struct page* back_page; struct page* netfs_page; } ;
struct cachefiles_object {int /*<<< orphan*/  backer; } ;
struct address_space {TYPE_1__* a_ops; } ;
struct TYPE_7__ {struct address_space* i_mapping; } ;
struct TYPE_5__ {int (* readpage ) (int /*<<< orphan*/ *,struct page*) ;} ;

/* Variables and functions */
 int EEXIST ; 
 int ENOBUFS ; 
 int ENOMEM ; 
 scalar_t__ PageError (struct page*) ; 
 scalar_t__ PageUptodate (struct page*) ; 
 struct page* __page_cache_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _debug (char*,...) ; 
 int /*<<< orphan*/  _enter (char*) ; 
 int /*<<< orphan*/  _leave (char*,...) ; 
 int /*<<< orphan*/  add_page_wait_queue (struct page*,TYPE_2__*) ; 
 int add_to_page_cache_lru (struct page*,struct address_space*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cachefiles_gfp ; 
 int /*<<< orphan*/  cachefiles_io_error_obj (struct cachefiles_object*,char*) ; 
 int /*<<< orphan*/  cachefiles_read_waiter ; 
 int /*<<< orphan*/  copy_highpage (struct page*,struct page*) ; 
 TYPE_3__* d_backing_inode (int /*<<< orphan*/ ) ; 
 struct page* find_get_page (struct address_space*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fscache_end_io (struct fscache_retrieval*,struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fscache_get_retrieval (struct fscache_retrieval*) ; 
 int /*<<< orphan*/  fscache_mark_page_cached (struct fscache_retrieval*,struct page*) ; 
 int /*<<< orphan*/  fscache_put_retrieval (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fscache_retrieval_complete (struct fscache_retrieval*,int) ; 
 int /*<<< orphan*/  get_page (struct page*) ; 
 int /*<<< orphan*/  init_waitqueue_func_entry (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct cachefiles_one_read*) ; 
 struct cachefiles_one_read* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  page_count (struct page*) ; 
 int /*<<< orphan*/  put_page (struct page*) ; 
 int stub1 (int /*<<< orphan*/ *,struct page*) ; 
 scalar_t__ trylock_page (struct page*) ; 
 int /*<<< orphan*/  unlock_page (struct page*) ; 

__attribute__((used)) static int cachefiles_read_backing_file_one(struct cachefiles_object *object,
					    struct fscache_retrieval *op,
					    struct page *netpage)
{
	struct cachefiles_one_read *monitor;
	struct address_space *bmapping;
	struct page *newpage, *backpage;
	int ret;

	_enter("");

	_debug("read back %p{%lu,%d}",
	       netpage, netpage->index, page_count(netpage));

	monitor = kzalloc(sizeof(*monitor), cachefiles_gfp);
	if (!monitor)
		goto nomem;

	monitor->netfs_page = netpage;
	monitor->op = fscache_get_retrieval(op);

	init_waitqueue_func_entry(&monitor->monitor, cachefiles_read_waiter);

	/* attempt to get hold of the backing page */
	bmapping = d_backing_inode(object->backer)->i_mapping;
	newpage = NULL;

	for (;;) {
		backpage = find_get_page(bmapping, netpage->index);
		if (backpage)
			goto backing_page_already_present;

		if (!newpage) {
			newpage = __page_cache_alloc(cachefiles_gfp);
			if (!newpage)
				goto nomem_monitor;
		}

		ret = add_to_page_cache_lru(newpage, bmapping,
					    netpage->index, cachefiles_gfp);
		if (ret == 0)
			goto installed_new_backing_page;
		if (ret != -EEXIST)
			goto nomem_page;
	}

	/* we've installed a new backing page, so now we need to start
	 * it reading */
installed_new_backing_page:
	_debug("- new %p", newpage);

	backpage = newpage;
	newpage = NULL;

read_backing_page:
	ret = bmapping->a_ops->readpage(NULL, backpage);
	if (ret < 0)
		goto read_error;

	/* set the monitor to transfer the data across */
monitor_backing_page:
	_debug("- monitor add");

	/* install the monitor */
	get_page(monitor->netfs_page);
	get_page(backpage);
	monitor->back_page = backpage;
	monitor->monitor.private = backpage;
	add_page_wait_queue(backpage, &monitor->monitor);
	monitor = NULL;

	/* but the page may have been read before the monitor was installed, so
	 * the monitor may miss the event - so we have to ensure that we do get
	 * one in such a case */
	if (trylock_page(backpage)) {
		_debug("jumpstart %p {%lx}", backpage, backpage->flags);
		unlock_page(backpage);
	}
	goto success;

	/* if the backing page is already present, it can be in one of
	 * three states: read in progress, read failed or read okay */
backing_page_already_present:
	_debug("- present");

	if (newpage) {
		put_page(newpage);
		newpage = NULL;
	}

	if (PageError(backpage))
		goto io_error;

	if (PageUptodate(backpage))
		goto backing_page_already_uptodate;

	if (!trylock_page(backpage))
		goto monitor_backing_page;
	_debug("read %p {%lx}", backpage, backpage->flags);
	goto read_backing_page;

	/* the backing page is already up to date, attach the netfs
	 * page to the pagecache and LRU and copy the data across */
backing_page_already_uptodate:
	_debug("- uptodate");

	fscache_mark_page_cached(op, netpage);

	copy_highpage(netpage, backpage);
	fscache_end_io(op, netpage, 0);
	fscache_retrieval_complete(op, 1);

success:
	_debug("success");
	ret = 0;

out:
	if (backpage)
		put_page(backpage);
	if (monitor) {
		fscache_put_retrieval(monitor->op);
		kfree(monitor);
	}
	_leave(" = %d", ret);
	return ret;

read_error:
	_debug("read error %d", ret);
	if (ret == -ENOMEM) {
		fscache_retrieval_complete(op, 1);
		goto out;
	}
io_error:
	cachefiles_io_error_obj(object, "Page read error on backing file");
	fscache_retrieval_complete(op, 1);
	ret = -ENOBUFS;
	goto out;

nomem_page:
	put_page(newpage);
nomem_monitor:
	fscache_put_retrieval(monitor->op);
	kfree(monitor);
nomem:
	fscache_retrieval_complete(op, 1);
	_leave(" = -ENOMEM");
	return -ENOMEM;
}