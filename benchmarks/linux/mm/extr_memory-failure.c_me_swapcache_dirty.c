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

/* Variables and functions */
 int /*<<< orphan*/  ClearPageDirty (struct page*) ; 
 int /*<<< orphan*/  ClearPageUptodate (struct page*) ; 
 int MF_DELAYED ; 
 int MF_FAILED ; 
 int /*<<< orphan*/  delete_from_lru_cache (struct page*) ; 

__attribute__((used)) static int me_swapcache_dirty(struct page *p, unsigned long pfn)
{
	ClearPageDirty(p);
	/* Trigger EIO in shmem: */
	ClearPageUptodate(p);

	if (!delete_from_lru_cache(p))
		return MF_DELAYED;
	else
		return MF_FAILED;
}