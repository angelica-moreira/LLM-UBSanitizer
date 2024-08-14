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
struct pt_regs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  array_map ; 
 long* bpf_map_lookup_elem (int /*<<< orphan*/ *,int*) ; 

int stress_array_map_lookup(struct pt_regs *ctx)
{
	u32 key = 1, i;
	long *value;

#pragma clang loop unroll(full)
	for (i = 0; i < 64; ++i)
		value = bpf_map_lookup_elem(&array_map, &key);

	return 0;
}