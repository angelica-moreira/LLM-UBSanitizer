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

/* Variables and functions */

__attribute__((used)) static int usage_id_cmp(const void *p1, const void *p2)
{
	if (*(int *)p1 < *(int *)p2)
		return -1;

	if (*(int *)p1 > *(int *)p2)
		return 1;

	return 0;
}