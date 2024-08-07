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
struct reada_zone {scalar_t__ elems; int /*<<< orphan*/  refcnt; int /*<<< orphan*/  lock; TYPE_1__* device; } ;
struct reada_extent {unsigned long logical; int nzones; struct reada_zone** zones; scalar_t__ refcnt; } ;
struct btrfs_fs_info {int /*<<< orphan*/  reada_lock; int /*<<< orphan*/  reada_tree; } ;
struct TYPE_2__ {int /*<<< orphan*/  reada_extents; } ;

/* Variables and functions */
 unsigned long PAGE_SHIFT ; 
 int /*<<< orphan*/  kfree (struct reada_extent*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  radix_tree_delete (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  reada_zone_release ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void reada_extent_put(struct btrfs_fs_info *fs_info,
			     struct reada_extent *re)
{
	int i;
	unsigned long index = re->logical >> PAGE_SHIFT;

	spin_lock(&fs_info->reada_lock);
	if (--re->refcnt) {
		spin_unlock(&fs_info->reada_lock);
		return;
	}

	radix_tree_delete(&fs_info->reada_tree, index);
	for (i = 0; i < re->nzones; ++i) {
		struct reada_zone *zone = re->zones[i];

		radix_tree_delete(&zone->device->reada_extents, index);
	}

	spin_unlock(&fs_info->reada_lock);

	for (i = 0; i < re->nzones; ++i) {
		struct reada_zone *zone = re->zones[i];

		kref_get(&zone->refcnt);
		spin_lock(&zone->lock);
		--zone->elems;
		if (zone->elems == 0) {
			/* no fs_info->reada_lock needed, as this can't be
			 * the last ref */
			kref_put(&zone->refcnt, reada_zone_release);
		}
		spin_unlock(&zone->lock);

		spin_lock(&fs_info->reada_lock);
		kref_put(&zone->refcnt, reada_zone_release);
		spin_unlock(&fs_info->reada_lock);
	}

	kfree(re);
}