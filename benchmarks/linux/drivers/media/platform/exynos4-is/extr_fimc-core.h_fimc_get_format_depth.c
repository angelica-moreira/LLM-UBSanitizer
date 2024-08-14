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
typedef  size_t u32 ;
struct fimc_fmt {size_t colplanes; scalar_t__* depth; } ;

/* Variables and functions */

__attribute__((used)) static inline u32 fimc_get_format_depth(struct fimc_fmt *ff)
{
	u32 i, depth = 0;

	if (ff != NULL)
		for (i = 0; i < ff->colplanes; i++)
			depth += ff->depth[i];
	return depth;
}