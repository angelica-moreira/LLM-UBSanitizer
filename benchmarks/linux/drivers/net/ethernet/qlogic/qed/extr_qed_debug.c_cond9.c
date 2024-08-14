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

__attribute__((used)) static u32 cond9(const u32 *r, const u32 *imm)
{
	return ((r[0] & imm[0]) >> imm[1]) !=
	    (((r[0] & imm[2]) >> imm[3]) | ((r[1] & imm[4]) << imm[5]));
}