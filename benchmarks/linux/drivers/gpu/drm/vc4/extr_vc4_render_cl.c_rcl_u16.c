#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct vc4_rcl_setup {scalar_t__ next_offset; TYPE_1__* rcl; } ;
struct TYPE_2__ {scalar_t__ vaddr; } ;

/* Variables and functions */

__attribute__((used)) static inline void rcl_u16(struct vc4_rcl_setup *setup, u16 val)
{
	*(u16 *)(setup->rcl->vaddr + setup->next_offset) = val;
	setup->next_offset += 2;
}