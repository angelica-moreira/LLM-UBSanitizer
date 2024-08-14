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
struct o2hb_region {unsigned long long hr_start_block; scalar_t__ hr_bdev; } ;
struct config_item {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t EINVAL ; 
 unsigned long long simple_strtoull (char*,char**,int /*<<< orphan*/ ) ; 
 struct o2hb_region* to_o2hb_region (struct config_item*) ; 

__attribute__((used)) static ssize_t o2hb_region_start_block_store(struct config_item *item,
					     const char *page,
					     size_t count)
{
	struct o2hb_region *reg = to_o2hb_region(item);
	unsigned long long tmp;
	char *p = (char *)page;

	if (reg->hr_bdev)
		return -EINVAL;

	tmp = simple_strtoull(p, &p, 0);
	if (!p || (*p && (*p != '\n')))
		return -EINVAL;

	reg->hr_start_block = tmp;

	return count;
}