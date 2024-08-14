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
struct hlist_bl_head {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int calc_max_buckets(void)
{
	/* use a fixed size of 2MB */
	unsigned long mem = 2 * 1024 * 1024;
	mem /= sizeof(struct hlist_bl_head);

	return mem;
}