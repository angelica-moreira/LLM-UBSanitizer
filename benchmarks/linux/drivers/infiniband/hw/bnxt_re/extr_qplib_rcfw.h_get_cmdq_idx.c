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
 int bnxt_qplib_max_cmdq_idx_per_pg (int) ; 

__attribute__((used)) static inline u32 get_cmdq_idx(u32 val, u32 depth)
{
	return val & (bnxt_qplib_max_cmdq_idx_per_pg(depth));
}