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
 int /*<<< orphan*/  BREAKPOINT_INSTRUCTION ; 
 int /*<<< orphan*/  memset32 (void*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static void bpf_jit_fill_ill_insns(void *area, unsigned int size)
{
	memset32(area, BREAKPOINT_INSTRUCTION, size/4);
}