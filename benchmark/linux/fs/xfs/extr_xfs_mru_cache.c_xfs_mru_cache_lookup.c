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
struct xfs_mru_cache_elem {int /*<<< orphan*/  list_node; } ;
struct xfs_mru_cache {int /*<<< orphan*/  lock; int /*<<< orphan*/  store; scalar_t__ lists; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  __release (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _xfs_mru_cache_list_insert (struct xfs_mru_cache*,struct xfs_mru_cache_elem*) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mru_lock ; 
 struct xfs_mru_cache_elem* radix_tree_lookup (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

struct xfs_mru_cache_elem *
xfs_mru_cache_lookup(
	struct xfs_mru_cache	*mru,
	unsigned long		key)
{
	struct xfs_mru_cache_elem *elem;

	ASSERT(mru && mru->lists);
	if (!mru || !mru->lists)
		return NULL;

	spin_lock(&mru->lock);
	elem = radix_tree_lookup(&mru->store, key);
	if (elem) {
		list_del(&elem->list_node);
		_xfs_mru_cache_list_insert(mru, elem);
		__release(mru_lock); /* help sparse not be stupid */
	} else
		spin_unlock(&mru->lock);

	return elem;
}