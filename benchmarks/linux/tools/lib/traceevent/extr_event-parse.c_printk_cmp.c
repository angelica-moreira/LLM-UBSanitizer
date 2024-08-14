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
struct printk_map {scalar_t__ addr; } ;

/* Variables and functions */

__attribute__((used)) static int printk_cmp(const void *a, const void *b)
{
	const struct printk_map *pa = a;
	const struct printk_map *pb = b;

	if (pa->addr < pb->addr)
		return -1;
	if (pa->addr > pb->addr)
		return 1;

	return 0;
}