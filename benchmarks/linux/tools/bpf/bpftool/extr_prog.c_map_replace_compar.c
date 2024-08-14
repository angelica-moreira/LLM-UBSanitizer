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
struct map_replace {int idx; } ;

/* Variables and functions */

__attribute__((used)) static int map_replace_compar(const void *p1, const void *p2)
{
	const struct map_replace *a = p1, *b = p2;

	return a->idx - b->idx;
}