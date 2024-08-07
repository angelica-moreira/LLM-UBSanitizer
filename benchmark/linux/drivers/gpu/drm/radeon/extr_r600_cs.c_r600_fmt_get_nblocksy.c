#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct TYPE_3__ {unsigned int blockheight; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_1__* color_formats_table ; 

int r600_fmt_get_nblocksy(u32 format, u32 h)
{
	unsigned bh;

	if (format >= ARRAY_SIZE(color_formats_table))
		return 0;

	bh = color_formats_table[format].blockheight;
	if (bh == 0)
		return 0;

	return (h + bh - 1) / bh;
}