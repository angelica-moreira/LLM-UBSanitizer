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
 int GENMASK (int,int) ; 

__attribute__((used)) static inline void xgene_set_bits(u32 *dst, u32 val, u32 start, u32 len)
{
	u32 end = start + len - 1;
	u32 mask = GENMASK(end, start);

	*dst &= ~mask;
	*dst |= (val << start) & mask;
}