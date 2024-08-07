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
typedef  int u8 ;

/* Variables and functions */
 int PATTERN_DST ; 
 int gen_inv_idx (int,int) ; 

__attribute__((used)) static inline u8 gen_dst_value(u8 index, bool is_memset)
{
	return PATTERN_DST | gen_inv_idx(index, is_memset);
}