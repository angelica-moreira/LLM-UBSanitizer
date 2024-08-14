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
struct hashmap {int cap; int sz; } ;

/* Variables and functions */

__attribute__((used)) static bool hashmap_needs_to_grow(struct hashmap *map)
{
	/* grow if empty or more than 75% filled */
	return (map->cap == 0) || ((map->sz + 1) * 4 / 3 > map->cap);
}