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
union uu {unsigned char* b; unsigned short us; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned short
get_unaligned16(const unsigned short *p)
{
	union uu  mm;
	unsigned char *b = (unsigned char *)p;

	mm.b[0] = b[0];
	mm.b[1] = b[1];
	return mm.us;
}