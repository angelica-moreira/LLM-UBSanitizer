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

__attribute__((used)) static inline void gmap_idte_one(unsigned long asce, unsigned long vaddr)
{
	asm volatile(
		"	.insn	rrf,0xb98e0000,%0,%1,0,0"
		: : "a" (asce), "a" (vaddr) : "cc", "memory");
}