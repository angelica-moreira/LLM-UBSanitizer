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
typedef  int /*<<< orphan*/  sysv_zone_t ;

/* Variables and functions */

__attribute__((used)) static inline int all_zeroes(sysv_zone_t *p, sysv_zone_t *q)
{
	while (p < q)
		if (*p++)
			return 0;
	return 1;
}