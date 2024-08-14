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
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  pattern_set_bit (int,int,int,char*) ; 
 scalar_t__ pattern_test_bit (int,int,int,char const*) ; 

__attribute__((used)) static inline void rotate_ud(const char *in, char *out, u32 width, u32 height)
{
	int i, j;
	int shift = (8 - (width % 8)) & 7;

	width = (width + 7) & ~7;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width - shift; j++) {
			if (pattern_test_bit(j, i, width, in))
				pattern_set_bit(width - (1 + j + shift),
						height - (1 + i),
						width, out);
		}

	}
}