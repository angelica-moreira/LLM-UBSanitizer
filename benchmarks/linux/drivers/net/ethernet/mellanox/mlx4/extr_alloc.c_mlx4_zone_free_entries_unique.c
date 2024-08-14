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
typedef  int u32 ;
struct mlx4_zone_entry {int dummy; } ;
struct mlx4_zone_allocator {int flags; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int EFAULT ; 
 int MLX4_ZONE_ALLOC_FLAGS_NO_OVERLAP ; 
 struct mlx4_zone_entry* __mlx4_find_zone_by_uid_unique (struct mlx4_zone_allocator*,int) ; 
 int /*<<< orphan*/  __mlx4_free_from_zone (struct mlx4_zone_entry*,int,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

u32 mlx4_zone_free_entries_unique(struct mlx4_zone_allocator *zones, u32 obj, u32 count)
{
	struct mlx4_zone_entry *zone;
	int res;

	if (!(zones->flags & MLX4_ZONE_ALLOC_FLAGS_NO_OVERLAP))
		return -EFAULT;

	spin_lock(&zones->lock);

	zone = __mlx4_find_zone_by_uid_unique(zones, obj);

	if (NULL == zone) {
		res = -1;
		goto out;
	}

	__mlx4_free_from_zone(zone, obj, count);
	res = 0;

out:
	spin_unlock(&zones->lock);

	return res;
}