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
 scalar_t__ expand_bits_16 ; 

__attribute__((used)) static void draw_byte_16(unsigned char *font, unsigned int *base, int rb)
{
	int l, bits;
	int fg = 0xFFFFFFFFUL;
	int bg = 0x00000000UL;
	unsigned int *eb = (int *)expand_bits_16;

	for (l = 0; l < 16; ++l)
	{
		bits = *font++;
		base[0] = (eb[bits >> 6] & fg) ^ bg;
		base[1] = (eb[(bits >> 4) & 3] & fg) ^ bg;
		base[2] = (eb[(bits >> 2) & 3] & fg) ^ bg;
		base[3] = (eb[bits & 3] & fg) ^ bg;
		base = (unsigned int *) ((char *)base + rb);
	}
}