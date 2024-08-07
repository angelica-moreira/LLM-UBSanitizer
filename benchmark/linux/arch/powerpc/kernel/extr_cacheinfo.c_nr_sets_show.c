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
struct kobject {int dummy; } ;
struct kobj_attribute {int dummy; } ;
struct cache {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 scalar_t__ cache_nr_sets (struct cache*,unsigned int*) ; 
 struct cache* index_kobj_to_cache (struct kobject*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,unsigned int) ; 

__attribute__((used)) static ssize_t nr_sets_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
	unsigned int nr_sets;
	struct cache *cache;

	cache = index_kobj_to_cache(k);

	if (cache_nr_sets(cache, &nr_sets))
		return -ENODEV;

	return sprintf(buf, "%u\n", nr_sets);
}