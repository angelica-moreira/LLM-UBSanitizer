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
 scalar_t__ not_useful (unsigned char*,int) ; 

__attribute__((used)) static void nubus_rewind(unsigned char **ptr, int len, int map)
{
	unsigned char *p = *ptr;

	while (len) {
		do {
			p--;
		} while (not_useful(p, map));
		len--;
	}
	*ptr = p;
}