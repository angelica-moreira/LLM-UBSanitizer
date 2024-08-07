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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  addr_t ;

/* Variables and functions */

__attribute__((used)) static inline u8 rdfs8(addr_t addr)
{
	u8 v;
	asm volatile("movb %%fs:%1,%0" : "=q" (v) : "m" (*(u8 *)addr));
	return v;
}