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
struct page {int dummy; } ;
struct lruvec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ClearPageActive (struct page*) ; 
 int /*<<< orphan*/  ClearPageReferenced (struct page*) ; 
 int /*<<< orphan*/  PGDEACTIVATE ; 
 int /*<<< orphan*/  PGROTATED ; 
 int PageActive (struct page*) ; 
 scalar_t__ PageDirty (struct page*) ; 
 int /*<<< orphan*/  PageLRU (struct page*) ; 
 scalar_t__ PageUnevictable (struct page*) ; 
 scalar_t__ PageWriteback (struct page*) ; 
 int /*<<< orphan*/  SetPageReclaim (struct page*) ; 
 int /*<<< orphan*/  __count_vm_event (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  add_page_to_lru_list (struct page*,struct lruvec*,int) ; 
 int /*<<< orphan*/  add_page_to_lru_list_tail (struct page*,struct lruvec*,int) ; 
 int /*<<< orphan*/  del_page_from_lru_list (struct page*,struct lruvec*,int) ; 
 int page_is_file_cache (struct page*) ; 
 int page_lru_base_type (struct page*) ; 
 scalar_t__ page_mapped (struct page*) ; 
 int /*<<< orphan*/  update_page_reclaim_stat (struct lruvec*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void lru_deactivate_file_fn(struct page *page, struct lruvec *lruvec,
			      void *arg)
{
	int lru, file;
	bool active;

	if (!PageLRU(page))
		return;

	if (PageUnevictable(page))
		return;

	/* Some processes are using the page */
	if (page_mapped(page))
		return;

	active = PageActive(page);
	file = page_is_file_cache(page);
	lru = page_lru_base_type(page);

	del_page_from_lru_list(page, lruvec, lru + active);
	ClearPageActive(page);
	ClearPageReferenced(page);

	if (PageWriteback(page) || PageDirty(page)) {
		/*
		 * PG_reclaim could be raced with end_page_writeback
		 * It can make readahead confusing.  But race window
		 * is _really_ small and  it's non-critical problem.
		 */
		add_page_to_lru_list(page, lruvec, lru);
		SetPageReclaim(page);
	} else {
		/*
		 * The page's writeback ends up during pagevec
		 * We moves tha page into tail of inactive.
		 */
		add_page_to_lru_list_tail(page, lruvec, lru);
		__count_vm_event(PGROTATED);
	}

	if (active)
		__count_vm_event(PGDEACTIVATE);
	update_page_reclaim_stat(lruvec, file, 0);
}